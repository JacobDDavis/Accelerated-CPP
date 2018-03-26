#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;
using std::ifstream;
using std::istream;

struct Student_info {
  string name;
  double grade;
};

double median(vector<double> vec) {
    typedef vector<double>::size_type vec_sz;

    vec_sz size = vec.size();
    if (size == 0)
        throw domain_error("median of an empty vector");
    sort(vec.begin(), vec.end());

    vec_sz mid = size/2;

    return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

//compute a student's overall grade from midterm and final exam grades and homework grade
double grade(double midterm, double final, double homework) {
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

//compute a student's overall grade from midterm and final exam grades and vector of homework grades
//this function does NOT copy its argument, because median does so for us
double grade(double midterm, double final, const vector<double>& hw) {
    if (hw.size() == 0)
        throw domain_error("student has done no homework");
    return grade(midterm, final, median(hw));
}

double grade(const Student_info& s) {
    return s.grade;
}

// read homework grades from an input stream into a `vector<double>'
istream& read_hw(istream& in, vector<double>& hw) {
  if (in) {
    // get rid of previous contents
    hw.clear();

    // read homework grades
    double x;
    while (in >> x)
      hw.push_back(x);

    // clear the stream so that input will work for the next student
    in.clear();
  }

  return in;
}

istream& read(istream& is, Student_info& s) {
  double midterm, final;
  // read and store the student's name and midterm and final exam grades
  is >> s.name >> midterm >> final;

  vector<double> homework;
  read_hw(is, homework);  // read and store all the student's homework grades

  if (cin)
    s.grade = grade(midterm, final, homework);

  return is;
}

bool compare(const Student_info& x, const Student_info& y) {
  return x.name < y.name;
}

int main() {
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    // read and store all the records, and find the length of the longest name
    // uses a grades file to speed up testing
  try {
    ifstream infile("Path/To/File.txt");
    while (read(infile, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }
  } catch (domain_error e) {
    cout << e.what() << endl;
  }

    // alphabetize the student records
    sort(students.begin(), students.end(), compare);

    // write the names and grades
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i)
    {
        //write the name, padded on the right to maxlen + 1 characters
   cout << students[i].name
        << string(maxlen + 1 - students[i].name.size(), ' ');

   // compute and write the grade
   double final_grade = grade(students[i]);
   streamsize prec = cout.precision();
   cout << setprecision(3) << final_grade
        << setprecision(prec);

   cout << endl;
       }
    return 0;
}
