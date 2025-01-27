#include "CppUnitTest.h"
#include "angularvelocitycalculator.h"
#include "pointreader.h"
#include "point.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(AngularVelocityTest)
    {
    public:
        TEST_METHOD(TestAngularVelocityWithValidData)
        {
            const char* filename = "Puntuak9.txt";
            struct point_t* points;
            int numberOfPoints = readPoints(filename, &points);

            Assert::IsTrue(numberOfPoints > 0, L"El número de puntos debe ser mayor que 0");

            double maxAngularVelocity = computeMaximumAngularVelocity(points, numberOfPoints);
            Logger::WriteMessage("In TestAngularVelocityWithValidData");
            Assert::IsTrue(maxAngularVelocity > 0, L"La velocidad angular máxima debe ser mayor que 0");

            free(points);
        }

        TEST_METHOD(TestAngularVelocityWithInvalidData)
        {
            const char* filename = "InvalidData.txt";
            struct point_t* points;
            int numberOfPoints = readPoints(filename, &points);

            Assert::AreEqual(numberOfPoints, -1, L"El número de puntos debe ser -1 para datos inválidos");
        }

        TEST_METHOD(TestAngularVelocityWithNonExistentFile)
        {
            const char* filename = "NonExistentFile.txt";
            struct point_t* points;
            int numberOfPoints = readPoints(filename, &points);

            Assert::AreEqual(numberOfPoints, -2, L"El número de puntos debe ser -2 para un archivo inexistente");
        }
    };
}
