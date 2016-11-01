#include "Graphic.h"

const GLfloat Graphic::STATIC_FIGURES[106][4] = {{4.066366f, 3.216887f, 3.216887f, 4.066366f },
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
                                                 {4.500000f, 1.745000f, 2.570000f, 3.445000f },
                                                 {3.216887f, 4.066366f, 3.216887f, 4.066366f },
                                                 {1.247753f, 3.249805f, 1.247753f, 3.249805f },
                                                 {0.956997f, 2.629469f, 0.956997f, 2.629469f },
                                                 {4.216887f, 4.216887f, 5.066366f, 5.066366f },
                                                 {1.712899f, 2.163092f, 1.712899f, 2.163092f } };

void Graphic::render() {
    //LOGI("Graphic::render(); Cx: %f; Cy: %f; Cc: %d; Rx: %f; Ry: %f;", CENTER_X, CENTER_Y, count, radius[0], radius[1]);
    // Need draw this object?
    if(!isVisible)
        return;
    setValues();

    // Use render shader programm
    glUseProgram(programID);
    checkGLError("Graphic - glUseProgram");

    // Choose you texture
    glBindTexture(GL_TEXTURE_2D, textureID);
    checkGLError("Graphic - glBindTexture");

    // Fill attributes and uniforms
    // Init position
    glVertexAttribPointer(starsAngle, 1, GL_FLOAT, GL_FALSE, 0, arrayPosition);
    checkGLError("Graphic - glVertexAttribPointer - graphicAngle");
    glEnableVertexAttribArray(starsAngle);
    checkGLError("Graphic - glVertexAttribPointer - graphicAngle - enabled");

    // For color
    glVertexAttribPointer(starColor, 4, GL_FLOAT, GL_FALSE, 0, arrayColor);
    checkGLError("Graphic - glVertexAttribPointer - graphicColor");
    glEnableVertexAttribArray(starColor);
    checkGLError("Graphic - glVertexAttribPointer - graphicColor - enabled");

    // Center
    glUniform2f(starCenter, centerX, centerY);
    checkGLError("Graphic - glUniform2f - graphicCenter");

    // Radius
    glUniform2f(starRadius, radiusX, radiusY);
    checkGLError("Graphic - glUniform2f - graphicRadius");

    // Arguments
    glUniform4f(starArguments, arguments[0], arguments[1], arguments[2], arguments[3]);
    checkGLError("Graphic - glUniform4f - graphicArguments");

    // Size of point
    glUniform1f(starSize, SIZE_POINT);
    checkGLError("Graphic - glUniform1f - graphicSize");

    // Delta speed
    glUniform1f(starTotalDeltaSpeed, totalDeltaSpeed);
    checkGLError("Graphic - glUniform2f - deltaPositionUniform");

    // Draw poligon
    glDrawArrays(GL_POINTS, 0, count);
    checkGLError("Graphic - glDrawArrays");

    // Off attributes
    glDisableVertexAttribArray(starsAngle);
    glDisableVertexAttribArray(starColor);
}

void Graphic::init(){
    // Parameters for functions
    // Default arguments
    Methods::fillArray(arguments, 1.0f, SIZE_ARRAYS);
    // Default strict
    Methods::fillArray(maxStrictArgument, 5.0f, SIZE_ARRAYS);
    // For static type
    GLuint randRow = Methods::getStrictRandom(101);
    GLfloat deltaStartPositions = 0.0f;
    // For uniform buffer settings
    GLfloat upperStrictUniform;
    GLfloat startUniformPositionX;
    GLfloat startUniformPositionY;
    GLfloat endsUniformPositionX;
    GLfloat endsUniformPositionY;

    // User choice
    switch(type){
        case DYNAMIC_UNIFORM :
            // For uniform starting and ends positions
            startUniformPositionX = (GLfloat)(Methods::getStrictModRandom(1000, 5)) / 1000.0f + STRICT_ARGUMENTS_MIN;
            startUniformPositionY = (GLfloat)(Methods::getStrictModRandom(1000, 5)) / 1000.0f + STRICT_ARGUMENTS_MIN;
            deltaStartPositions = startUniformPositionX - startUniformPositionY;
            endsUniformPositionX = deltaStartPositions > 0? STRICT_ARGUMENTS_MAX : STRICT_ARGUMENTS_MAX + deltaStartPositions;
            endsUniformPositionY = deltaStartPositions < 0? STRICT_ARGUMENTS_MAX : STRICT_ARGUMENTS_MAX - deltaStartPositions;

            for(int i = 0; i < SIZE_ARRAYS; i++){
                if(i % 2 == 0){
                    minStrictArgument[i] = startUniformPositionX;
                    maxStrictArgument[i] = endsUniformPositionX;
                    arguments[i] = minStrictArgument[i];
                } else {
                    minStrictArgument[i] = startUniformPositionY;
                    maxStrictArgument[i] = endsUniformPositionY;
                    arguments[i] = minStrictArgument[i];
                }

                // Speed of transform
                dArgumentsTransformSpeed[i] = DARGUMENT_ARRAY_SPEED;
            }

            break;
        case DYNAMIC_RANDOM :
            for(int i = 0; i < SIZE_ARRAYS; i++){
                // Get upper strict
                maxStrictArgument[i] = (GLfloat)Methods::getStrictModRandom(100, 5) / 100.0f + STRICT_ARGUMENTS_MAX;
                // Get lower strict
                minStrictArgument[i] = (GLfloat)Methods::getStrictModRandom(100, 5) / 100.0f + STRICT_ARGUMENTS_MIN;
                // Start values
                arguments[i] = minStrictArgument[i];
                // Speed of transform
                dArgumentsTransformSpeed[i] = DARGUMENT_ARRAY_SPEED * 4.0f;
            }
            break;
        case STATIC_RANDOM :
            arguments[0] = STATIC_FIGURES[randRow][0];
            arguments[1] = STATIC_FIGURES[randRow][1];
            arguments[2] = STATIC_FIGURES[randRow][2];
            arguments[3] = STATIC_FIGURES[randRow][3];
            break;
        case HYPOCYCLOID :
            Methods::fillArray(arguments, 1.1f, SIZE_ARRAYS);
            break;
        case EPICYCLOID :
            Methods::fillArray(arguments, 3.1f, SIZE_ARRAYS);
            break;
    }

    // Delta speed
    dParticlesSpeed = 0.01f;
    // Current speed
    totalDeltaSpeed = 0.0f;
    // Init colors
    arrayColor = new GLfloat[count * 4];
    Methods::fillArrayRGBA(arrayColor, count, 0.0f, 1.0f, 0.0f, 1.0f);
    GLfloat colorStart = 0.5f;
    GLfloat colorStep = colorStart / (GLfloat) count;
    GLfloat redColor = 0.0f, greenColor = 0.0f, blueColor = 0.0f;
    GLuint partOfCount = count / 2;
    switch(Methods::getStrictRandom(3)){
        case 0 : redColor = 1.0f; break;
        case 1 : greenColor = 1.0f; break;
        case 2 : blueColor = 1.0f; break;
    }

    // 4 color
    switch(color){
        case RED:
            for(int i = 0; i < count; i++){
                arrayColor[i * 4] = colorStart += colorStep;
                arrayColor[i * 4 + 1] = 0.0f;
                arrayColor[i * 4 + 2] = 0.0f;
                arrayColor[i * 4 + 3] = 1.0f;
            }
            break;
        case GREEN:
            for(int i = 0; i < count; i++){
                arrayColor[i * 4] = 0.0f;
                arrayColor[i * 4 + 1] = colorStart += colorStep;
                arrayColor[i * 4 + 2] = 0.0f;
                arrayColor[i * 4 + 3] = 1.0f;
            }
            break;
        case BLUE:
            for(int i = 0; i < count; i++){
                arrayColor[i * 4] = 0.0f;
                arrayColor[i * 4 + 1] = 0.0f;
                arrayColor[i * 4 + 2] = colorStart += colorStep;
                arrayColor[i * 4 + 3] = 1.0f;
            }
            break;
        case GOLD:
            for(int i = 0; i < count; i++){
                if(i > partOfCount){
                    redColor = greenColor = blueColor = 1.0f;
                }

                arrayColor[i * 4] = redColor;
                arrayColor[i * 4 + 1] = greenColor;
                arrayColor[i * 4 + 2] = blueColor;
                arrayColor[i * 4 + 3] = 1.0f;
            }
            break;
    }

    // Initial position
    arrayPosition = new GLfloat[count];
    for(int i = 0; i < count; i++)
        arrayPosition[i] = (GLfloat)i;

    //LOGI("Graphic::init - ARGS(); %ff, %ff, %ff, %ff", arguments[0], arguments[1], arguments[2], arguments[3]);
}

void Graphic::setValues(){
    // For change common points direction
    if(totalDeltaSpeed > STRICT_SPEED_MAX || totalDeltaSpeed < STRICT_SPEED_MIN)
        dParticlesSpeed = -dParticlesSpeed;
    totalDeltaSpeed += dParticlesSpeed;

    // For full dynamic random
    if(DYNAMIC_RANDOM == type || DYNAMIC_UNIFORM == type){
        // Upper strict
        // Reset each argument if it large or less strict
        // Because user can change arguments, by touching screen
        // And it can out of visible surface
        for(int i = 0; i < SIZE_ARRAYS; i++){
            // Upper strict
            if(arguments[i] > maxStrictArgument[i]){
                // Change point direction
                dArgumentsTransformSpeed[i] = -fabsf(dArgumentsTransformSpeed[i]);
                // Reset values
                arguments[i] = maxStrictArgument[i];
            }

            // Lower strict
            if(arguments[i] < minStrictArgument[i]){
                // Change point direction
                dArgumentsTransformSpeed[i] = fabsf(dArgumentsTransformSpeed[i]);
                // Reset values
                arguments[i] = minStrictArgument[i];
            }

            // Move points
            if(isChange)
                arguments[i] += dArgumentsTransformSpeed[i];
        }
    }

    //LOGI("Graphic::setValues - ARGS(); %ff, %ff, %ff, %ff", arguments[0], arguments[1], arguments[2], arguments[3]);
    //LOGI("Graphic::setValues - DELTA(); %ff, %ff, %ff, %ff", dArgumentsTransformSpeed[0], dArgumentsTransformSpeed[1], dArgumentsTransformSpeed[2], dArgumentsTransformSpeed[3]);
}

void Graphic::setCoords(GLfloat x, GLfloat y){
    if(type != STATIC_RANDOM){
        /// Get value for change
        GLfloat actionX = x / STRICT_TOUCH_CHANGE;
        GLfloat actionY = y / STRICT_TOUCH_CHANGE;

        // Get direction
        GLfloat dActionX = previousActionX - actionX;
        GLfloat dActionY = previousActionY - actionY;
        // Save previous values
        previousActionX = actionX;
        previousActionY = actionY;

        // Change dX and dY for increase or decrease for full dynamic random
        if(type == DYNAMIC_RANDOM){
            if(dActionX > 0){
                arguments[0] += actionX;
                arguments[2] += actionX;
            } else {
                arguments[0] -= actionX;
                arguments[2] -= actionX;
            }

            // Change for dY for increase or decrease
            if(dActionY > 0){
                arguments[1] += actionY;
                arguments[3] += actionY;
            } else {
                arguments[1] -= actionY;
                arguments[3] -= actionY;
            }
        }

        // Change dX for increase or decrease for dynamic uniform
        if(type == DYNAMIC_UNIFORM){
            if(dActionX > 0){
                arguments[0] += actionX;
                arguments[2] += actionX;
                arguments[1] += actionX;
                arguments[3] += actionX;
            } else {
                arguments[0] -= actionX;
                arguments[2] -= actionX;
                arguments[1] -= actionX;
                arguments[3] -= actionX;
            }
        }
    }
}

void Graphic::setSettings(COLOR_TYPE color, FUNCTION_TYPE type, bool isChange){
    this->color = color;
    this->type = type;
    this->isChange = isChange;

    // Wait while, programs end work
    while(this->isProgramWork);
    // Don't draw program
    isVisible = false;
    delete [] arrayPosition;
    delete [] arrayColor;
    // Change settings
    init();
    // Program can draw
    isVisible = true;
}