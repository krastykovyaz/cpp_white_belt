#include <iostream>
#include <string>
using namespace std;

struct Specialization{
    string specialization;
    explicit Specialization(string value){
        specialization = value;
    }
};

struct Course{
    string course;
    explicit Course(string value){
        course = value;
    }
};

struct Week{
    string week;
    explicit Week(string value){
        week = value;
    }
};

struct LectureTitle {
  string specialization;
  string course;
  string week;
  LectureTitle(Specialization n_specialization, Course n_course, Week n_week){
      specialization = n_specialization.specialization;
      course = n_course.course;
      week = n_week.week;
  }
};

void PrintLec(const LectureTitle& lec){
    cout << lec.specialization << " | " << lec.course << " | " << lec.week << endl;
}

// int main(){
//     // LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};
// //     LectureTitle title(
// //     Specialization("C++"),
// //     Course("White belt"),
// //     Week("4th")
// // );
// // LectureTitle title(string("C++"), string("White belt"), string("4th"));
// // LectureTitle title(
// //     Course("White belt"),
// //     Specialization("C++"),
// //     Week("4th")
// // );
// // LectureTitle title(
// //     Specialization("C++"),
// //     Week("4th"),
// //     Course("White belt")
// // );
// // LectureTitle title = {"C++", "White belt", "4th"};
// //     PrintLec(title);
//     return 0;
// }
