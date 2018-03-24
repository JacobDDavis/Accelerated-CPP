#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main()
{
    vector<string> students;
    vector<double> finalGrades;
    typedef vector<double>::size_type vec_sz;
    typedef vector<string>::size_type strvec_sz;
    
    for(int i = 0; i < 2; i++) {
        cout << "Please enter your first name: ";
        string name = "";
        cin >> name;
        students.push_back(name);
    
        // ask for and read the midterm and final grades
        cout << "Please enter your midterm and final exam grades: ";
        double midterm, final;
        cin >> midterm >> final;
    
        // ask for the homework grades
        cout << "Enter all of your homework grades, "
        "followed by end-of-file: ";
    
        // the number and sum of grades read so far
        vector<double> homework;
        double x;
    
        // invariant: homework contains all the homework grades read so far
        while (cin >> x && x != -1)
            homework.push_back(x);
    
        // check that the student entered some homework grades
        vec_sz size = homework.size();
        if (size == 0) {
            cout << endl << "You must enter your grades. "
            "Please try again." << endl;
            return 1;
        }
    
        //sort the grades
        sort(homework.begin(), homework.end());
    
        // compute the median homework grade
        vec_sz mid = size/2;
        double median;
        median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2
        : homework[mid];
        
        double fgrade = 0.2 * midterm + 0.4 * final + 0.4 * median;
        
        finalGrades.push_back(fgrade);
        homework.clear();
    }
    vec_sz gds = 0;
    for (strvec_sz i = 0; i != students.size(); ++i)
    {
        cout << students[i] << ": " << finalGrades[gds] << endl;
        gds++;
    }
                              
    return 0;
}


