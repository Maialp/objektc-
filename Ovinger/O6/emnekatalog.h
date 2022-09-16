#pragma once
#include "std_lib_facilities.h"
#include "file.h"

class CourseCatalog{
    private:
        map<string, string> courseMap;
    public:
        CourseCatalog();  //Deafult konstruktør
        void addCourse(string kode, string navn);
        void removeCourse(string kode);
        string getCourse(string kode);
        
        void readToFile(string fileName,const CourseCatalog& courseCatalog);

        friend ostream& operator<<(ostream&,const CourseCatalog& courseCatalog);
};