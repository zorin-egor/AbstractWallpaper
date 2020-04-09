#ifndef INTERSECT_H
#define INTERSECT_H

#include <GLES2/gl2.h>
#include <cmath>
#include <vector>

#include "Methods.h"
#include "Structures.h"

class Intersect {

    private:

        template <class A>
        static float determinate(A a, A b, A c, A d) {
            return a * d - b * c;
        }

        template <class A>
        static CommonLine<A> coefficients(A x1, A y1, A x2, A y2) {
            CommonLine<A> coeff;
            coeff.a = y1 - y2;
            coeff.b = x2 - x1;
            coeff.c = -1 * coeff.a * x1 - coeff.b * y1;
            return coeff;
        }

        template <class A>
        static bool intersect(Line<A> * line1, Line<A> * line2, Point<A> * crossPoint) {
            CommonLine<A> coeff1 = Intersect::coefficients(*(line1->x1), *(line1->y1), *(line1->x2), *(line1->y2));
            CommonLine<A> coeff2 = Intersect::coefficients(*(line2->x1), *(line2->y1), *(line2->x2), *(line2->y2));

            A D0 = determinate (coeff1.a, coeff1.b, coeff2.a, coeff2.b);
            A Dx = determinate (coeff1.b, coeff1.c, coeff2.b, coeff2.c);
            A Dy = -determinate (coeff1.a, coeff1.c, coeff2.a, coeff2.c);

            if (fabs(D0) < Intersect::getEps()) {
                return false;
            }

            crossPoint->x = Dx / D0;
            crossPoint->y = Dy / D0;

            return true;
        }

    public:

        inline static const float getEps() {
            return 0.000001f;
        }

        template <class A>
        inline static bool between (A a, A b, A c) {
            return Methods::getMin(a,b) <= c + Intersect::getEps() && c <= Methods::getMax(a, b) + Intersect::getEps();
        }

        template <class A>
        inline static bool betweenLine(Line<A> * line, A x, A y) {
            return between(*(line->x1), *(line->x2), x) && between (*(line->y1), *(line->y2), y);
        }

        template <class A>
        static bool intersectSegments(Line<A> * line1, Line<A> * line2, std::vector<A> * twoPoints) {
            Point<A> point;

            if (Intersect::intersect(line1, line2, &point)) {
                if (betweenLine(line1, point.x, point.y) && betweenLine(line2, point.x, point.y)) {
                    twoPoints->push_back(point.x);
                    twoPoints->push_back(point.y);
                    return true;
                }
            }

            return false;
        }

        template <class A>
        static bool intersectSegmentsAndLines(Line<A> * line1, Line<A> * line2, std::vector<A> * twoPoints) {
            Point<A> point;

            if (Intersect::intersect(line1, line2, &point)) {
                if (betweenLine(line1, point.x, point.y)) {
                    twoPoints->push_back(point.x);
                    twoPoints->push_back(point.y);
                    return true;
                }
            }

            return false;
        }

        template <class A>
        static bool intersectLines(Line<A> * line1, Line<A> * line2, std::vector<A> * twoPoints) {
            Point<A> point;

            if (Intersect::intersect(line1, line2, &point)) {
                twoPoints->push_back(point.x);
                twoPoints->push_back(point.y);
                return true;
            }

            return true;
        }

        template <class A>
        static bool intersectRect(Rectangle<A> * rect1, Rectangle<A> * rect2, std::vector<A> * crossPoints) {
            for(int i = 0; i < 4; i++) {
                for(int j = 0; j < 4; j++) {
                    intersectSegments(rect1->iterateSides.at(i), rect2->iterateSides.at(j), crossPoints);
                }
            }

            return crossPoints->size() >= 4? true : false;
        }
};

#endif
