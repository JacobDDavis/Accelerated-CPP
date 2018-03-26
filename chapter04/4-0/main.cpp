#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>
#include "grade.h"
#include "Student_info.h"

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
//using std::istream;

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;
    
    // read and store all the records, and find the length of the longest name
    // uses a grades file to speed up testing
    ifstream infile("/Path/To/File.txt");
    while (read(infile, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }
    
    // alphabetize the student records
    sort(students.begin(), students.end(), compare);
    
    // write the names and grades
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i)
    {
        //write the name, padded on the right to maxlen + 1 characters
        cout << students[i].name
        << string(maxlen + 1 - students[i].name.size(), ' ');
        
        //compute and write the grade
        try
        {
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
            << setprecision(prec);
        }
        catch (domain_error e)
        {
            cout << e.what();
        }
        cout << endl;
    }
    return 0;
}
