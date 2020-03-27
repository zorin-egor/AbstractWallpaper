#include "Main.h"

Main::~Main(){
    LOGI("~Main();");
    // Java delete GL data itself?
    // Because GL context lost!
    //glUseProgram(0);
    //glDeleteProgram(programGraphic);
    delete pTextures;
    deleteObjects();
}

bool Main::init(){
    // Compiling and link program
    programGraphic = MakeShaders::createProgram(MakeShaders::v_star_shader, MakeShaders::f_star_shader);
    if(programGraphic == 0)
        return false;

    // Clear compiliers
    glReleaseShaderCompiler();

    graphicAngle = glGetAttribLocation(programGraphic, "a_ArrayAngle");
    checkGLError("Main::init - stars - a_ArraySpeed");

    graphicColor = glGetAttribLocation(programGraphic, "a_ArrayColor");
    checkGLError("Main::init - stars - a_ArrayColor");

    graphicCenter = glGetUniformLocation(programGraphic, "u_Center");
    checkGLError("Main::init - stars - u_Center");

    graphicRadius = glGetUniformLocation(programGraphic, "u_Radius");
    checkGLError("Main::init - stars - u_Radius");

    graphicArguments = glGetUniformLocation(programGraphic, "u_Arguments");
    checkGLError("Main::init - stars - u_Arguments");

    graphicSize = glGetUniformLocation(programGraphic, "u_PointSize");
    checkGLError("Main::init - stars - u_PointSize");

    graphicTotalDeltaSpeed = glGetUniformLocation(programGraphic, "u_TotalDeltaSpeed");
    checkGLError("Main::init - stars - u_TotalDeltaSpeed");

    //On alfa-blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    checkGLError("Main::init - glBlendFunc");
    glEnable(GL_BLEND);
    checkGLError("Main::init - glEnable");

    // Get slots of img
    pTextures = new ManageTexture(env, pngManager, assetManager);

    return true;
}

void Main::onChange(int width, int height, int color, int form, bool isChange, int count){
    this->width = width > 0? width : this->width;
    this->height = height > 0? height : this->height;
    this->color = color >= 0? color : this->color;
    this->form = form >= 0? form : this->form;
    this->isChange = isChange;
    this->count = (count >= 100 && count <= 50000)? count : width + height > 1500? POINTS_COUNT + 5000 : POINTS_COUNT;
    coefficient = (float) this->width / (float) this->height;

    // Recreate view objects with new settings
    deleteObjects();
    createObjects();

    // Set viewport
    glViewport(0, 0, width, height);
    checkGLError("Main::onChange - glViewport");
}

void Main::createObjects() {
    // Get only one object for draw
    pGraphic = new Graphic(Graphic::FUNCTION_TYPE(form),
                           Graphic::COLOR_TYPE(color),
                           isChange,
                           count,
                           0.0f,
                           0.0f,
                           SHAPE_RADIUS / coefficient,
                           SHAPE_RADIUS,
                           programGraphic,
                           pTextures->getTexturesPackIDs(ManageTexture::PARTICLES),
                           graphicAngle,
                           graphicColor,
                           graphicCenter,
                           graphicRadius,
                           graphicArguments,
                           graphicSize,
                           graphicTotalDeltaSpeed);
}

void Main::deleteObjects(){
    if(pGraphic != NULL){
        delete pGraphic;
        pGraphic = NULL;
    }
}

void Main::step(){
    // Clear screen
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    checkGLError("Main::step - glClearColor");
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    checkGLError("Main::step - glClear");

    // Draw star
    pGraphic->render();
}

void Main::action(GLfloat x, GLfloat y){
    //LOGI("X: %f; Y: %f;", x, y);
    pGraphic->setCoords(x, y);
}

void Main::setSettings(int color, int form){
    pGraphic->setSettings(Graphic::COLOR_TYPE(color), Graphic::FUNCTION_TYPE(form));
}

void Main::setIsChange(bool isChange){
    pGraphic->setIsChange(isChange);
}