#include "Graphic.h"

const GLfloat Graphic::STATIC_FIGURES[107][4] = {
                                                    {4.066366f, 3.216887f, 3.216887f, 4.066366f },
                                                    {3.052000f, 5.706000f, 0.410000f, 5.570000f },
                                                    {0.799000f, 4.739000f, 3.516000f, 5.549000f },
                                                    {1.115000f, 1.653000f, 4.792000f, 2.859000f },
                                                    {5.785000f, 5.138000f, 2.147000f, 5.327000f },
                                                    { 4.351000f, 4.454000f, 2.716000f, 4.023000f },
                                                    { 4.194000f, 3.090000f, 0.836000f, 4.650000f },
                                                    { 2.575000f, 5.304000f, 5.354000f, 0.799000f },
                                                    { 3.443000f, 5.958000f, 1.280000f, 1.636000f },
                                                    { 5.283000f, 2.450000f, 1.576000f, 1.016000f },
                                                    { 3.854000f, 3.603000f, 2.233000f, 4.318000f },
                                                    { 5.724000f, 2.244000f, 0.224000f, 2.823000f },
                                                    { 3.999000f, 4.386000f, 2.001000f, 4.051000f },
                                                    { 2.500000f, 2.788000f, 4.728000f, 4.846000f },
                                                    { 3.156000f, 4.744000f, 3.948000f, 2.256000f },
                                                    { 0.717000f, 5.288000f, 3.739000f, 4.155000f },
                                                    { 3.049000f, 2.763000f, 3.147000f, 4.426000f },
                                                    { 5.252000f, 3.839000f, 1.052000f, 3.575000f },
                                                    { 0.600000f, 0.411000f, 2.147000f, 2.473000f },
                                                    { 3.302000f, 1.259000f, 5.248000f, 3.820000f },
                                                    { 1.151000f, 4.821000f, 0.051000f, 2.940000f },
                                                    { 5.174000f, 1.682000f, 3.065000f, 3.362000f },
                                                    { 5.165000f, 5.089000f, 3.033000f, 1.502000f },
                                                    { 2.709000f, 4.460000f, 4.552000f, 2.362000f },
                                                    { 0.575000f, 5.183000f, 4.854000f, 4.546000f },
                                                    { 0.767000f, 4.466000f, 1.966000f, 5.676000f },
                                                    { 0.556000f, 4.974000f, 2.250000f, 2.923000f },
                                                    { 4.578000f, 2.513000f, 0.711000f, 1.312000f },
                                                    { 5.920000f, 1.539000f, 4.052000f, 5.324000f },
                                                    { 3.803000f, 3.835000f, 0.740000f, 5.893000f },
                                                    { 1.008000f, 4.945000f, 1.006000f, 3.806000f },
                                                    { 2.552000f, 4.378000f, 2.368000f, 1.293000f },
                                                    { 3.379000f, 4.930000f, 2.475000f, 3.194000f },
                                                    { 1.002000f, 4.761000f, 4.998000f, 4.872000f },
                                                    { 0.271000f, 3.915000f, 5.476000f, 5.803000f },
                                                    { 4.938000f, 2.456000f, 4.593000f, 4.913000f },
                                                    { 1.040000f, 2.729000f, 3.540000f, 5.145000f },
                                                    { 4.926000f, 1.705000f, 1.714000f, 4.732000f },
                                                    { 5.739000f, 3.770000f, 4.177000f, 1.505000f },
                                                    { 2.366000f, 5.405000f, 4.183000f, 5.485000f },
                                                    { 4.747000f, 3.545000f, 4.030000f, 5.521000f },
                                                    { 3.536000f, 5.497000f, 0.976000f, 3.801000f },
                                                    { 4.333000f, 5.455000f, 3.250000f, 5.189000f },
                                                    { 3.120000f, 1.452000f, 0.280000f, 1.814000f },
                                                    { 1.381000f, 1.983000f, 0.524000f, 1.448000f },
                                                    { 4.488000f, 5.181000f, 1.938000f, 5.843000f },
                                                    { 5.373000f, 5.196000f, 3.343000f, 4.734000f },
                                                    { 0.450000f, 2.715000f, 5.450000f, 4.509000f },
                                                    { 3.104000f, 4.681000f, 3.104000f, 4.681000f },
                                                    { 2.430000f, 2.788000f, 2.430000f, 2.788000f },
                                                    { 0.142000f, 1.346000f, 0.142000f, 1.346000f },
                                                    { 5.850000f, 5.367000f, 5.850000f, 5.367000f },
                                                    { 4.856000f, 2.856000f, 4.856000f, 2.856000f },
                                                    { 2.025000f, 1.579000f, 2.025000f, 1.579000f },
                                                    { 4.052000f, 0.481000f, 4.052000f, 0.481000f },
                                                    { 3.824000f, 1.017000f, 3.824000f, 1.017000f },
                                                    { 0.758000f, 1.892000f, 0.758000f, 1.892000f },
                                                    { 3.019000f, 2.913000f, 3.019000f, 2.913000f },
                                                    { 2.896000f, 2.887000f, 2.896000f, 2.887000f },
                                                    { 1.522000f, 1.451000f, 1.522000f, 1.451000f },
                                                    { 0.570000f, 2.506000f, 0.570000f, 2.506000f },
                                                    { 1.499000f, 0.665000f, 1.499000f, 0.665000f },
                                                    { 1.286000f, 4.242000f, 1.286000f, 4.242000f },
                                                    { 4.244000f, 1.503000f, 4.244000f, 1.503000f },
                                                    { 5.713000f, 1.655000f, 5.713000f, 1.655000f },
                                                    { 2.463000f, 1.150000f, 2.463000f, 1.150000f },
                                                    { 3.299000f, 1.140000f, 3.299000f, 1.140000f },
                                                    { 2.150000f, 2.299000f, 2.150000f, 2.299000f },
                                                    { 5.854000f, 0.486000f, 5.854000f, 0.486000f },
                                                    { 5.495000f, 5.495000f, 1.505000f, 1.505000f },
                                                    { 2.675000f, 2.675000f, 2.325000f, 2.325000f },
                                                    { 2.265000f, 2.265000f, 2.470000f, 2.470000f },
                                                    { 4.245000f, 4.245000f, 3.490000f, 3.490000f },
                                                    { 4.740000f, 1.110000f, 0.260000f, 5.760000f },
                                                    { 4.680000f, 1.790000f, 3.340000f, 2.495000f },
                                                    { 1.330000f, 4.140000f, 1.600000f, 1.335000f },
                                                    { 0.030000f, 2.385000f, 1.955000f, 4.635000f },
                                                    { 1.160000f, 2.265000f, 1.660000f, 1.395000f },
                                                    { 5.150000f, 3.765000f, 0.650000f, 2.790000f },
                                                    { 0.305000f, 1.515000f, 4.085000f, 5.370000f },
                                                    { 4.710000f, 3.675000f, 4.000000f, 2.180000f },
                                                    { 4.495000f, 1.445000f, 2.000000f, 0.755000f },
                                                    { 1.200000f, 2.540000f, 5.530000f, 5.385000f },
                                                    { 4.740000f, 5.860000f, 0.870000f, 2.090000f },
                                                    { 2.435000f, 2.255000f, 1.435000f, 3.390000f },
                                                    { 5.340000f, 3.745000f, 0.750000f, 2.665000f },
                                                    { 1.870000f, 2.955000f, 0.935000f, 3.385000f },
                                                    { 2.400000f, 2.215000f, 5.030000f, 5.435000f },
                                                    { 3.330000f, 3.850000f, 3.500000f, 1.445000f },
                                                    { 3.425000f, 3.635000f, 2.285000f, 2.375000f },
                                                    { 0.560000f, 1.515000f, 4.440000f, 3.645000f },
                                                    { 1.800000f, 1.990000f, 2.620000f, 4.875000f },
                                                    { 4.070000f, 4.875000f, 3.000000f, 1.080000f },
                                                    { 3.830000f, 2.610000f, 0.585000f, 2.955000f },
                                                    { 2.205000f, 1.860000f, 2.410000f, 5.180000f },
                                                    { 4.000000f, 1.345000f, 3.775000f, 4.165000f },
                                                    { 4.655000f, 5.840000f, 1.750000f, 4.055000f },
                                                    { 3.290000f, 4.000000f, 3.790000f, 2.095000f },
                                                    { 3.000000f, 3.170000f, 4.630000f, 2.435000f },
                                                    { 0.230000f, 5.910000f, 0.875000f, 0.790000f },
                                                    { 4.500000f, 1.745000f, 2.570000f, 3.445000f },
                                                    { 3.216887f, 4.066366f, 3.216887f, 4.066366f },
                                                    { 1.247753f, 3.249805f, 1.247753f, 3.249805f },
                                                    { 0.956997f, 2.629469f, 0.956997f, 2.629469f },
                                                    { 4.216887f, 4.216887f, 5.066366f, 5.066366f },
                                                    { 4.283176f, 3.518178f, 3.683177f, 3.668177f },
                                                    { 1.712899f, 2.163092f, 1.712899f, 2.163092f }
};


const GLfloat Graphic::STRICT_SPEED_MAX = 10000.0f;
const GLfloat Graphic::STRICT_SPEED_MIN = 0.0f;
const GLfloat Graphic::STRICT_ARGUMENTS_MAX = 5.0f;
const GLfloat Graphic::STRICT_ARGUMENTS_MIN = 1.1f;
const GLfloat Graphic::ARGUMENT_ARRAY_SPEED = 0.000001f;
const GLfloat Graphic::STRICT_TOUCH_CHANGE = 10000.0f;
const GLfloat Graphic::SIZE_POINT = 5.0f;


Graphic::Graphic(FUNCTION_TYPE type,
                 COLOR_TYPE color,
                 bool isChange,
                 GLuint count,
                 GLfloat centerX,
                 GLfloat centerY,
                 GLfloat radiusX,
                 GLfloat radiusY,
                 GLuint programID,
                 GLuint textureID,
                 GLuint starsAngle,
                 GLuint starColor,
                 GLuint starCenter,
                 GLuint starRadius,
                 GLuint starArguments,
                 GLuint starSize,
                 GLuint starTotalDeltaSpeed) : m_oType(type),
                                               m_oColor(color),
                                               m_bIsChange(isChange),
                                               m_nCount(count),
                                               m_fCenterX(centerX),
                                               m_fCenterY(centerY),
                                               m_fRadiusX(radiusX),
                                               m_fRadiusY(radiusY),
                                               m_nProgramId(programID),
                                               m_nTextureId(textureID),
                                               m_nStarsAngle(starsAngle),
                                               m_nStarColor(starColor),
                                               m_nStarCenter(starCenter),
                                               m_nStarRadius(starRadius),
                                               m_nStarArguments(starArguments),
                                               m_nStarSize(starSize),
                                               m_nStarTotalDeltaSpeed(starTotalDeltaSpeed)
{
    LOGI("Graphic::Graphic()");
    m_fPreviousActionX = 0.0f;
    m_fPreviousActionY = 0.0f;
    m_bIsVisible = true;
    init();
}

Graphic::~Graphic() {
    LOGI("Graphic::~Graphic()");
    delete [] m_pArrayPosition;
    delete [] m_pArrayColor;
}

void Graphic::init() {
    // Parameters for functions
    // Default arguments
    Methods::fillArray(m_fArguments, 1.0f, SIZE_ARRAYS);
    // Default strict
    Methods::fillArray(m_fMaxStrictArgument, 5.0f, SIZE_ARRAYS);
    // For static type
    GLuint randRow = Methods::getStrictRandom(107);
    GLfloat deltaStartPositions = 0.0f;
    // For uniform buffer settings
    GLfloat startUniformPositionX;
    GLfloat startUniformPositionY;
    GLfloat endsUniformPositionX;
    GLfloat endsUniformPositionY;

    // User choice
    switch(m_oType) {
        case DYNAMIC_UNIFORM: {
            // For uniform starting and ends positions
            startUniformPositionX = (GLfloat)(Methods::getStrictModRandom(1000, 5)) / 1000.0f + STRICT_ARGUMENTS_MIN;
            startUniformPositionY = (GLfloat)(Methods::getStrictModRandom(1000, 5)) / 1000.0f + STRICT_ARGUMENTS_MIN;
            deltaStartPositions = startUniformPositionX - startUniformPositionY;
            endsUniformPositionX = deltaStartPositions > 0? STRICT_ARGUMENTS_MAX : STRICT_ARGUMENTS_MAX + deltaStartPositions;
            endsUniformPositionY = deltaStartPositions < 0? STRICT_ARGUMENTS_MAX : STRICT_ARGUMENTS_MAX - deltaStartPositions;

            for (int i = 0; i < SIZE_ARRAYS; i++) {
                if (i % 2 == 0) {
                    m_fMinStrictArgument[i] = startUniformPositionX;
                    m_fMaxStrictArgument[i] = endsUniformPositionX;
                    m_fArguments[i] = m_fMinStrictArgument[i];
                } else {
                    m_fMinStrictArgument[i] = startUniformPositionY;
                    m_fMaxStrictArgument[i] = endsUniformPositionY;
                    m_fArguments[i] = m_fMinStrictArgument[i];
                }

                // Speed of transform
                m_fArgumentsTransformSpeed[i] = ARGUMENT_ARRAY_SPEED;
            }

            break;
        }

        case DYNAMIC_RANDOM: {
            for (int i = 0; i < SIZE_ARRAYS; i++) {
                // Get upper strict
                m_fMaxStrictArgument[i] = (GLfloat)Methods::getStrictModRandom(100, 5) / 100.0f + STRICT_ARGUMENTS_MAX;
                // Get lower strict
                m_fMinStrictArgument[i] = (GLfloat)Methods::getStrictModRandom(100, 5) / 100.0f + STRICT_ARGUMENTS_MIN;
                // Start values
                m_fArguments[i] = m_fMinStrictArgument[i];
                // Speed of transform
                m_fArgumentsTransformSpeed[i] = ARGUMENT_ARRAY_SPEED * 4.0f;
            }
            break;
        }

        case STATIC_RANDOM: {
            m_fArguments[0] = STATIC_FIGURES[randRow][0];
            m_fArguments[1] = STATIC_FIGURES[randRow][1];
            m_fArguments[2] = STATIC_FIGURES[randRow][2];
            m_fArguments[3] = STATIC_FIGURES[randRow][3];
            break;
        }

        case HYPOCYCLOID: {
            Methods::fillArray(m_fArguments, 1.1f, SIZE_ARRAYS);
            break;
        }

        case EPICYCLOID: {
            Methods::fillArray(m_fArguments, 3.1f, SIZE_ARRAYS);
            break;
        }
    }

    // Delta speed
    m_fParticlesSpeed = 0.01f;
    // Current speed
    m_fTotalDeltaSpeed = STRICT_SPEED_MIN;
    // Init colors
    m_pArrayColor = new GLfloat[m_nCount * 4];
    Methods::fillArrayRGBA(m_pArrayColor, m_nCount, 0.0f, 1.0f, 0.0f, 1.0f);
    GLfloat colorStart = 0.5f;
    GLfloat colorStep = colorStart / (GLfloat) m_nCount;
    GLfloat redColor = 0.0f;
    GLfloat greenColor = 0.0f;
    GLfloat blueColor = 0.0f;
    GLuint partOfCount = m_nCount / 2;

    switch (Methods::getStrictRandom(3)) {
        case 0 : redColor = 1.0f; break;
        case 1 : greenColor = 1.0f; break;
        case 2 : blueColor = 1.0f; break;
    }

    // 4 color
    switch (m_oColor) {
        case RED: {
            for(int i = 0; i < m_nCount; i++) {
                m_pArrayColor[i * 4] = colorStart += colorStep;
                m_pArrayColor[i * 4 + 1] = 0.0f;
                m_pArrayColor[i * 4 + 2] = 0.0f;
                m_pArrayColor[i * 4 + 3] = 1.0f;
            }
            break;
        }

        case GREEN: {
            for(int i = 0; i < m_nCount; i++) {
                m_pArrayColor[i * 4] = 0.0f;
                m_pArrayColor[i * 4 + 1] = colorStart += colorStep;
                m_pArrayColor[i * 4 + 2] = 0.0f;
                m_pArrayColor[i * 4 + 3] = 1.0f;
            }
            break;
        }

        case BLUE: {
            for(int i = 0; i < m_nCount; i++) {
                m_pArrayColor[i * 4] = 0.0f;
                m_pArrayColor[i * 4 + 1] = 0.0f;
                m_pArrayColor[i * 4 + 2] = colorStart += colorStep;
                m_pArrayColor[i * 4 + 3] = 1.0f;
            }
            break;
        }

        case RAND: {
            for (int i = 0; i < m_nCount; i++) {
                if (i > partOfCount) {
                    redColor = greenColor = blueColor = 1.0f;
                }

                m_pArrayColor[i * 4] = redColor;
                m_pArrayColor[i * 4 + 1] = greenColor;
                m_pArrayColor[i * 4 + 2] = blueColor;
                m_pArrayColor[i * 4 + 3] = 1.0f;
            }
            break;
        }
    }

    // Initial position
    m_pArrayPosition = new GLfloat[m_nCount];
    for (int i = 0; i < m_nCount; i++) {
        m_pArrayPosition[i] = (GLfloat)i;
    }
}

void Graphic::setValues() {
    // For change common points direction
    if (m_fTotalDeltaSpeed > STRICT_SPEED_MAX || m_fTotalDeltaSpeed < STRICT_SPEED_MIN) {
        m_fParticlesSpeed = -m_fParticlesSpeed;
    }

    m_fTotalDeltaSpeed += m_fParticlesSpeed;

    // For full dynamic random
    if (DYNAMIC_RANDOM == m_oType || DYNAMIC_UNIFORM == m_oType) {
        // Upper strict
        // Reset each argument if it large or less strict
        // Because user can change arguments, by touching screen
        // And it can out of visible surface
        for (int i = 0; i < SIZE_ARRAYS; i++) {
            // Upper strict
            if (m_fArguments[i] > m_fMaxStrictArgument[i]) {
                // Change point direction
                m_fArgumentsTransformSpeed[i] = -fabsf(m_fArgumentsTransformSpeed[i]);
                // Reset values
                m_fArguments[i] = m_fMaxStrictArgument[i];
            }

            // Lower strict
            if (m_fArguments[i] < m_fMinStrictArgument[i]) {
                // Change point direction
                m_fArgumentsTransformSpeed[i] = fabsf(m_fArgumentsTransformSpeed[i]);
                // Reset values
                m_fArguments[i] = m_fMinStrictArgument[i];
            }

            // Move points
            if (m_bIsChange) {
                m_fArguments[i] += m_fArgumentsTransformSpeed[i];
            }
        }
    }

    LOGI("Graphic::setValues - ARGS(); %ff, %ff, %ff, %ff", m_fArguments[0], m_fArguments[1], m_fArguments[2], m_fArguments[3]);
    LOGI("Graphic::setValues - DELTA(); %ff, %ff, %ff, %ff", m_fArgumentsTransformSpeed[0], m_fArgumentsTransformSpeed[1], m_fArgumentsTransformSpeed[2], m_fArgumentsTransformSpeed[3]);
}

void Graphic::render() {
    if (!m_bIsVisible) {
        return;
    }

    m_oDrawMutex.lock();
    
    setValues();

    // Use render shader program
    glUseProgram(m_nProgramId);
    checkGLError("Graphic - glUseProgram");

    // Choose you texture
    glBindTexture(GL_TEXTURE_2D, m_nTextureId);
    checkGLError("Graphic - glBindTexture");

    // Fill attributes and uniforms
    // Init position
    glVertexAttribPointer(m_nStarsAngle, 1, GL_FLOAT, GL_FALSE, 0, m_pArrayPosition);
    checkGLError("Graphic - glVertexAttribPointer - m_nGraphicAngle");
    glEnableVertexAttribArray(m_nStarsAngle);
    checkGLError("Graphic - glVertexAttribPointer - m_nGraphicAngle - enabled");

    // For color
    glVertexAttribPointer(m_nStarColor, 4, GL_FLOAT, GL_FALSE, 0, m_pArrayColor);
    checkGLError("Graphic - glVertexAttribPointer - m_nGraphicColor");
    glEnableVertexAttribArray(m_nStarColor);
    checkGLError("Graphic - glVertexAttribPointer - m_nGraphicColor - enabled");

    // Center
    glUniform2f(m_nStarCenter, m_fCenterX, m_fCenterY);
    checkGLError("Graphic - glUniform2f - m_nGraphicCenter");

    // Radius
    glUniform2f(m_nStarRadius, m_fRadiusX, m_fRadiusY);
    checkGLError("Graphic - glUniform2f - m_nGraphicRadius");

    // Arguments
    glUniform4f(m_nStarArguments, m_fArguments[0], m_fArguments[1], m_fArguments[2], m_fArguments[3]);
    checkGLError("Graphic - glUniform4f - m_nGraphicArguments");

    // Size of point
    glUniform1f(m_nStarSize, SIZE_POINT);
    checkGLError("Graphic - glUniform1f - m_nGraphicSize");

    // Delta speed
    glUniform1f(m_nStarTotalDeltaSpeed, m_fTotalDeltaSpeed);
    checkGLError("Graphic - glUniform2f - deltaPositionUniform");

    // Draw polygon
    glDrawArrays(GL_POINTS, 0, m_nCount);
    checkGLError("Graphic - glDrawArrays");

    // Off attributes
    glDisableVertexAttribArray(m_nStarsAngle);
    glDisableVertexAttribArray(m_nStarColor);

    m_oDrawMutex.unlock();
}

void Graphic::setCoords(GLfloat x, GLfloat y) {
    if (m_oType != STATIC_RANDOM) {
        /// Get value for change
        GLfloat actionX = x / STRICT_TOUCH_CHANGE;
        GLfloat actionY = y / STRICT_TOUCH_CHANGE;

        // Get direction
        GLfloat dActionX = m_fPreviousActionX - actionX;
        GLfloat dActionY = m_fPreviousActionY - actionY;
        // Save previous values
        m_fPreviousActionX = actionX;
        m_fPreviousActionY = actionY;

        // Change dX and dY for increase or decrease for full dynamic random
        if (m_oType == DYNAMIC_RANDOM) {
            if (dActionX > 0) {
                m_fArguments[0] += actionX;
                m_fArguments[2] += actionX;
            } else {
                m_fArguments[0] -= actionX;
                m_fArguments[2] -= actionX;
            }

            // Change for dY for increase or decrease
            if (dActionY > 0) {
                m_fArguments[1] += actionY;
                m_fArguments[3] += actionY;
            } else {
                m_fArguments[1] -= actionY;
                m_fArguments[3] -= actionY;
            }
        }

        // Change dX for increase or decrease for dynamic uniform
        if (m_oType == DYNAMIC_UNIFORM) {
            if (dActionX > 0) {
                m_fArguments[0] += actionX;
                m_fArguments[2] += actionX;
                m_fArguments[1] += actionX;
                m_fArguments[3] += actionX;
            } else {
                m_fArguments[0] -= actionX;
                m_fArguments[2] -= actionX;
                m_fArguments[1] -= actionX;
                m_fArguments[3] -= actionX;
            }
        }
    }
}

void Graphic::setSettings(COLOR_TYPE color, FUNCTION_TYPE type) {
    m_oDrawMutex.lock();

    m_oColor = color;
    m_oType = type;

    delete [] m_pArrayPosition;
    delete [] m_pArrayColor;
    init();

    m_oDrawMutex.unlock();
}

void Graphic::setIsChange(bool isChange) {
    m_bIsChange = isChange;
}