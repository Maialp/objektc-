#include "emnekatalog.h"

 CourseCatalog::CourseCatalog(){}

void CourseCatalog::addCourse(string kode, string navn){
    courseMap[kode]=navn;
}
void CourseCatalog::removeCourse(string kode){
    courseMap.erase(kode);
}
string CourseCatalog::getCourse(string kode){
    return courseMap[kode];
}

ostream& operator<<(ostream& os,const CourseCatalog& courseCatalog){
    for(const auto& i : courseCatalog.courseMap){
        os << i.first << ','<< i.second << endl;
    }
    return os;
}
void CourseCatalog::readToFile(string fileName,const CourseCatalog& courseCatalog){
    ofstream myFile{fileName};
    if (!myFile){
        error("Cannot open file");
    }
    operator<<(myFile, courseCatalog);
}
