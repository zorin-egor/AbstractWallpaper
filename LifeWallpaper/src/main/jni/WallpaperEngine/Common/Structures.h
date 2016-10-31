#ifndef LIFEWALLPAPERTREE_STRUCTURES_H
#define LIFEWALLPAPERTREE_STRUCTURES_H

#include <GLES2/gl2.h>
#include <vector>
#include <cmath>
#include <WallpaperEngine/Common/Methods.h>

// Common types
template<class A>
struct Point {
    A x;
    A y;
};

//Real coords of object
template<class A>
struct Line {
    A * x1;
    A * y1;
    A * x2;
    A * y2;

    A getCenterX(){
        return Methods::getMin(*x1, *x2) + (Methods::getMax(*x1, *x2) - Methods::getMin(*x1, *x2)) * (A)0.5f;
    }

    A getCenterY(){
        return Methods::getMin(*y1, *y2) + (Methods::getMax(*y1, *y2) - Methods::getMin(*y1, *y2)) * (A)0.5f;
    }

    Point<A> getCenterXY(){
        Point<A> point;
        point.x = getCenterX();
        point.y = getCenterY();
        return point;
    }

    static A getCenter(A a, A b){
        return Methods::getMin(a, b) + (Methods::getMax(a, b) - Methods::getMin(a, b)) * (A)0.5f;
    }
};

template <class A>
struct CommonLine {
    A a, b, c;
};

template<class A>
struct Rectangle {

    std::vector<Line<A> *> iterateSides;

    Line<A> left;
    Line<A> down;
    Line<A> right;
    Line<A> up;

    Rectangle(){
        iterateSides.push_back(&left);
        iterateSides.push_back(&down);
        iterateSides.push_back(&right);
        iterateSides.push_back(&up);
    }

    void setRectangle(A * rectangleArray){
        left.x1 = &rectangleArray[0];
        left.y1 = &rectangleArray[1];
        left.x2 = &rectangleArray[2];
        left.y2 = &rectangleArray[3];

        down.x1 = &rectangleArray[2];
        down.y1 = &rectangleArray[3];
        down.x2 = &rectangleArray[4];
        down.y2 = &rectangleArray[5];

        right.x1 = &rectangleArray[4];
        right.y1 = &rectangleArray[5];
        right.x2 = &rectangleArray[6];
        right.y2 = &rectangleArray[7];

        up.x1 = &rectangleArray[0];
        up.y1 = &rectangleArray[1];
        up.x2 = &rectangleArray[6];
        up.y2 = &rectangleArray[7];
    }

    Point<A> getCenter(){
        Point<A> centerPoint;
        centerPoint.x = *(up.x2) + (*(up.x1) - *(up.x2)) * 0.5f;
        centerPoint.y = *(left.y1) - (*(left.y1) - *(left.y2)) * (A)0.5f;
        return centerPoint;
    }

    static Point<A> getCenter(A * rectangleArray){
        Point<A> centerPoint;
        centerPoint.x = rectangleArray[0] + (rectangleArray[6] - rectangleArray[0]) * 0.5f;
        centerPoint.y = rectangleArray[1] - (rectangleArray[1] - rectangleArray[3]) * 0.5f;
        return centerPoint;
    }
};

// Work with vectors and matrix
class Matrix {

    private:
        // Pick all arrays links
        std::vector<GLfloat *> arrayLInks;

    public:

        // Position of texture
        // 0 - 1 - 2 - 3
        //  .   .   .
        // 12 - 13 - 14 -15
        static const enum TEXTURE_COORDS {  ONE = 0, TWO = 1, THREE = 2, FOUR = 3,
                                            FIFE = 4, SIX = 5, SEVEN = 6, EIGHT  = 7,
                                            NINE = 8, TEN = 9, ELEVEN = 10, TWELVE = 11,
                                            THIRTEEN  = 12, FOURTEEN = 13, FIFTEEN = 14, SIXTEEN = 15 };

        // Choose axis
        static const enum COORDINATES { X = 1, Y = 2, Z = 3};

        ~Matrix(){
            // Clear all link on arrays
            if(!arrayLInks.empty())
                for (std::vector<GLfloat *>::iterator it = arrayLInks.begin(); it != arrayLInks.end(); it++)
                    delete [] *it;
        }

        // Matrix for move-rotate-scale
        GLfloat * getDefaultMatrix4x4(){
            GLfloat * matrix = new GLfloat[16];
            arrayLInks.push_back(matrix);

            // 1 строка
            matrix[0] = 1.0f;
            matrix[1] = 0.0f;
            matrix[2] = 0.0f;
            matrix[3] = 0.0f;

            // 2 строка
            matrix[4] = 0.0f;
            matrix[5] = 1.0f;
            matrix[6] = 0.0f;
            matrix[7] = 0.0f;

            // 3 строка
            matrix[8] = 0.0f;
            matrix[9] = 0.0f;
            matrix[10] = 1.0f;
            matrix[11] = 0.0f;

            // 4 строка
            matrix[12] = 0.0f;
            matrix[13] = 0.0f;
            matrix[14] = 0.0f;
            matrix[15] = 1.0f;

            return matrix;
        }

        // Matrix for texture position
        GLfloat * getDefaultTextureCoord(){
            // 1---4
            // |   |
            // 2---3

            GLfloat * texture = new GLfloat[8];
            arrayLInks.push_back(texture);

            // 1 вершина
            texture[0] = 0.0f;
            texture[1] = 0.0f;

            // 2 вершина
            texture[2] = 0.0f;
            texture[3] = 1.0f;

            // 3 вершина
            texture[4] = 1.0f;
            texture[5] = 1.0f;

            // 4 вершина
            texture[6] = 1.0f;
            texture[7] = 0.0f;

            return texture;
        }

        // Matrix for position on screen
        GLfloat * getDefaultVerticesCoords(){
            // 1---4
            // | \ |
            // 2---3

            GLfloat * vertices = new GLfloat[8];
            arrayLInks.push_back(vertices);

            // 1 вершина
            vertices[0] = -1.0f;
            vertices[1] = 1.0f;

            // 2 вершина
            vertices[2] = -1.0f;
            vertices[3] = -1.0f;

            // 3 вершина
            vertices[4] = 1.0f;
            vertices[5] = -1.0f;

            // 4 вершина
            vertices[6] = 1.0f;
            vertices[7] = 1.0f;

            return vertices;
        }

        // Rotate texture coordinates. X and Y - 2 point
        static GLfloat * rotateTextureCoord(GLfloat * textureCoords, int rotate){
            for(int i = 0; i < rotate * 2; i++)
                Methods::shiftArrayRight(textureCoords, 8);

            return textureCoords;
        }


        // Set texture coordinates with number
        static GLfloat * setTextureCoords(GLfloat * textureCoords, int x, int y, int number){
            int cells = x * y;

            if(0 <= number && number < cells && x > 0 && y > 0){
                float x_cell = 1.0f / (float) x;
                float y_cell = 1.0f / (float) y;

                float position = (float)number * x_cell;
                float new_y;
                float new_x = std::modf(position, &new_y);

                new_y *= y_cell;

                // 1 вершина
                textureCoords[0] = new_x;
                textureCoords[1] = new_y;

                // 2 вершина
                textureCoords[2] = new_x;
                textureCoords[3] = new_y + y_cell;

                // 3 вершина
                textureCoords[4] = new_x + x_cell;
                textureCoords[5] = new_y + y_cell;

                // 4 вершина
                textureCoords[6] = new_x + x_cell;
                textureCoords[7] = new_y;
            }

            return textureCoords;
        }

        // Move
        static GLfloat * setMoveMatrix4x4(GLfloat * textureCoords, GLfloat x, GLfloat y){
            textureCoords[12] = x;
            textureCoords[13] = y;
            textureCoords[14] = 1.0f;

            return textureCoords;
        }

        // Scale
        static  GLfloat * setScaleMatrix4x4(GLfloat * textureCoords, GLfloat x, GLfloat y){
            textureCoords[0] = 1.0f;
            textureCoords[5] = y;
            textureCoords[10] = x;

            return textureCoords;
        }

        // Rotate
        static  GLfloat * setRotateMatrix4x4(GLfloat * textureCoords, GLfloat a, COORDINATES axis){
            switch(axis){
                case X :
                    textureCoords[5] = cos(a);
                    textureCoords[6] = sin(a);
                    textureCoords[9] = -sin(a);
                    textureCoords[10] = cos(a);
                    break;
                case Y :
                    textureCoords[0] = cos(a);
                    textureCoords[2] = -sin(a);
                    textureCoords[8] = sin(a);
                    textureCoords[10] = cos(a);
                    break;
                case Z :
                    textureCoords[0] = cos(a);
                    textureCoords[1] = sin(a);
                    textureCoords[4] = -sin(a);
                    textureCoords[6] = cos(a);
                    break;
            }

            return textureCoords;
        }

        // Set position coordinates with WIDTH and WIDTH
        static GLfloat * setVerticesCoords(float x, float y, float width, float height, GLfloat * verticesCoords){

            // Top left
            verticesCoords[0] = x;
            verticesCoords[1] = y;

            // Bottom left
            verticesCoords[2] = x;
            verticesCoords[3] = y - height;

            // Bottom right
            verticesCoords[4] = x + width;
            verticesCoords[5] = y - height;

            // Top right
            verticesCoords[6] = x + width;
            verticesCoords[7] = y;

            return verticesCoords;
        }
};

#endif //LIFEWALLPAPERTREE_STRUCTURES_H
