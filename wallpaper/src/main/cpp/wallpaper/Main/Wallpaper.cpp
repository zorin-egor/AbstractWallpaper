#include "Wallpaper.h"

const int Wallpaper::POINTS_COUNT = 100;
const GLfloat Wallpaper::SHAPE_RADIUS = 0.35f;

Wallpaper::Wallpaper(JNIEnv * env, jobject assetManager, jobject bitmapManager) {
    LOGI("Wallpaper::Wallpaper();");
    m_pGraphic = nullptr;
    m_pTextures = nullptr;
    init(env, assetManager, bitmapManager);
}

Wallpaper::~Wallpaper() {
    LOGI("Wallpaper::~Wallpaper();");
    delete m_pTextures;
    deleteObjects();
}

bool Wallpaper::init(JNIEnv* env, jobject assetManager, jobject bitmapManager) {
    // Create texture manager
    m_pTextures = new TexturesManager(env, assetManager, bitmapManager);

    // Compiling and link program
    m_nProgramGraphic = MakeShaders::createProgram(MakeShaders::V_GRAPHIC_SHADER, MakeShaders::F_GRAPHIC_SHADER);
    if (m_nProgramGraphic == 0) {
        return false;
    }

    m_nGraphicAngle = glGetAttribLocation(m_nProgramGraphic, "a_ArrayAngle");
    checkGLError("Wallpaper::init - stars - a_ArraySpeed");

    m_nGraphicColor = glGetAttribLocation(m_nProgramGraphic, "a_ArrayColor");
    checkGLError("Wallpaper::init - stars - a_ArrayColor");

    m_nGraphicCenter = glGetUniformLocation(m_nProgramGraphic, "u_Center");
    checkGLError("Wallpaper::init - stars - u_Center");

    m_nGraphicRadius = glGetUniformLocation(m_nProgramGraphic, "u_Radius");
    checkGLError("Wallpaper::init - stars - u_Radius");

    m_nGraphicArguments = glGetUniformLocation(m_nProgramGraphic, "u_Arguments");
    checkGLError("Wallpaper::init - stars - u_Arguments");

    m_nGraphicSize = glGetUniformLocation(m_nProgramGraphic, "u_PointSize");
    checkGLError("Wallpaper::init - stars - u_PointSize");

    m_nGraphicTotalDeltaSpeed = glGetUniformLocation(m_nProgramGraphic, "u_TotalDeltaSpeed");
    checkGLError("Wallpaper::init - stars - u_TotalDeltaSpeed");

    // Clear compilers
    glReleaseShaderCompiler();

    //On alfa-blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    checkGLError("Wallpaper::init - glBlendFunc");
    glEnable(GL_BLEND);
    checkGLError("Wallpaper::init - glEnable");

    return true;
}

void Wallpaper::screen(int width, int height) {
    glViewport(0, 0, width, height);
    checkGLError("Wallpaper::screen - glViewport");

    auto isResize = m_nWidth != width || m_nHeight != height;

    m_nWidth = width;
    m_nHeight = height;
    m_fCoefficient = (float) width / (float) height;
    m_nCount = (m_nCount >= 100 && m_nCount <= 50000)? m_nCount : width + height > 1500? POINTS_COUNT + 5000 : POINTS_COUNT;

    // Recreate objects with new data
    if (isResize) {
        deleteObjects();
        createObjects();
    }
}

void Wallpaper::createObjects() {
    // Get only one object for draw
    m_pGraphic = new Graphic(m_oFuncType,
                             m_oColorType,
                             m_bIsChange,
                             m_nCount,
                             0.0f,
                             0.0f,
                             SHAPE_RADIUS / m_fCoefficient,
                             SHAPE_RADIUS,
                             m_nProgramGraphic,
                             m_pTextures->getTextureId(TexturesManager::PARTICLES),
                             m_nGraphicAngle,
                             m_nGraphicColor,
                             m_nGraphicCenter,
                             m_nGraphicRadius,
                             m_nGraphicArguments,
                             m_nGraphicSize,
                             m_nGraphicTotalDeltaSpeed);

    m_pGraphic->setCoords(m_nX, m_nY);
}

void Wallpaper::deleteObjects() {
    delete m_pGraphic;
    m_pGraphic = nullptr;
}

void Wallpaper::step() {
    m_oDrawMutex.lock();

    // Clear screen
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    checkGLError("Wallpaper::step - glClearColor");
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    checkGLError("Wallpaper::step - glClear");

    // Draw star
    m_pGraphic->render();

    m_oDrawMutex.unlock();
}

void Wallpaper::action(GLfloat x, GLfloat y) {
    m_nX = x;
    m_nY = y;

    if (m_pGraphic != nullptr) {
        m_pGraphic->setCoords(m_nX, m_nY);
    }
}

void Wallpaper::setSettings(int color, int form) {
    m_oColorType = Graphic::COLOR_TYPE(color);
    m_oFuncType = Graphic::FUNCTION_TYPE(form);

    if (m_pGraphic != nullptr) {
        m_pGraphic->setSettings(m_oColorType, m_oFuncType);
    }
}

void Wallpaper::setParticles(int count) {
    m_nCount = count;

    if (m_pGraphic != nullptr) {
        m_oDrawMutex.lock();
        deleteObjects();
        createObjects();
        m_oDrawMutex.unlock();
    }
}

void Wallpaper::setIsChange(bool isChange) {
    m_bIsChange = isChange;

    if (m_pGraphic != nullptr) {
        m_pGraphic->setIsChange(m_bIsChange);
    }
}