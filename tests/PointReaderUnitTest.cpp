#include "pointreader.h"
#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTest
{
    TEST_CLASS(PointReaderTest)
    {
    public:
        TEST_METHOD(TestReadingWorksWithValidInput)
        {
            char const* filename = "points.txt";
            struct point_t* points;
            
            int numberOfPoints = readPoints(filename, &points);
            Logger::WriteMessage("In TestReadingWorksWithValidInput");
            Assert::IsTrue(numberOfPoints > 0); 
        }//Si el archivo esta leido correctamente, el numero de puntos deveria de ser mayor que 0
		TEST_METHOD(TestReadingNotWorksWithInvalidInput)
		{

            point_t* points;
            int numberOfPoints = readPoints("invalidpoints.txt", &points);

			Logger::WriteMessage("In TestReadingNotWorksWithInvalidInput");
			Assert::AreEqual(numberOfPoints, -1);//Si no se lee bien , devuelve -1

		}
        TEST_METHOD(TestReadingNotWorksWithUnexsistentFile){

            point_t* points;
            int numberOfPoints = readPoints("points.txt", &points);
			Logger::WriteMessage("In TestReadingNotWorksWithUnexsistentFile");
			Assert::AreEqual(numberOfPoints, -2);
        }//Si el archivo no existe -2
    };
}
