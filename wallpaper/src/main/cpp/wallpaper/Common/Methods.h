#ifndef METHODS_H
#define METHODS_H

#include <ctime>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <GLES2/gl2.h>


#define PI 3.1415926535

class Methods {

    public:

        inline static float getFullRandom() {
            return (static_cast <float> (rand()) / static_cast <float>(RAND_MAX) * 2) - 1;
        }

        inline static float getShortRandom() {
            return static_cast <float> (rand()) / static_cast <float>(RAND_MAX);
        }

        inline static float convertCoordinatesToOpenGL(bool inverse, int screenSize, float coordinate) {
            return (coordinate / screenSize * 2 - 1) * (inverse? -1 : 1);
        }

        inline static int getStrictModRandom(int strict, int mod) {
            int value;
            while((value = (rand() % strict)) % mod != 0);
            return value;
        }

        inline static int getStrictRandom(int strict) {
            return rand() % strict;
        }

        static double roundTo(double value, double digits) {
            double powerOfTen = pow(10.0, digits);
            return (floor(value * powerOfTen) + 0.5) / powerOfTen;
        }

        template <class T>
        static void fillArrayRGBA(T * array, GLuint count, T red, T green, T blue, T transparency) {
            for (int i = 0; i < count; i++) {
                array[i * 4] = red;
                array[i * 4 + 1] = green;
                array[i * 4 + 2] = blue;
                array[i * 4 + 3] = transparency;
            }
        }

        template <class T>
        inline static T degreesToRadians(T degree) {
            return (degree * static_cast<T>(PI)) / 180.0;
        }

        template <class A, class B>
        static void fillArray(A * array, B content, int count) {
            for(int i = 0; i < count; i++) {
                array[i] = (A)content;
            }
        }

        static std::string fillLeft(std::string stringForFill, char symbol, int toLength) {
            int difference = toLength - stringForFill.length();
            if (difference > 0) {
                std::string buf(difference, symbol);
                stringForFill = buf + stringForFill;
            }

            return stringForFill;
        }

        static std::string intToString(int number) {
            std::string result = number == 0? "0" : "";

            while(number) {
                int x = number % 10;
                number /= 10;
                char i = '0';
                i = i + x;
                result = i + result;
            }

            return result;
        }

        template <class A>
        static A * shiftArrayLeft(A * array, int size) {
            A temp = array[0];

            for(int i = 1; i < size; i++) {
                array[i - 1] = array[i];
            }

            array[size - 1] = temp;
            return array;
        }

        template <class A>
        static A * shiftArrayRight(A * array, int size) {
            A temp = array[size - 1];

            for(int i = size - 1; i >= 0 ; i--) {
                array[i] = array[i - 1];
            }

            array[0] = temp;
            return array;
        }

        template <class A>
        static A * mirrorArray(A * array, int size) {
            A temp;

            for(int i = 0; i < size / 2; i++) {
                temp = array[i];
                array[i] = array[size - 1 - i];
                array[size - 1 - i] = temp;
            }

            return array;
        }

        inline static int getRandSign() {
            int sign[2] = {-1, 1};
            return sign[rand() % 2];
        }

        template <class A>
        inline static A getMin(A a, A b) {
            return a < b? a : b;
        }

        template <class A>
        inline static A getMax(A a, A b) {
            return a > b? a : b;
        }

        template <class A>
        inline static void swap(A & a, A & b) {
            A temp = b;
            b = a;
            a = temp;
        }
};

#endif
