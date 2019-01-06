#include <iostream>
#include <string>
using namespace std;

class employee{ 
    private:
        string name; 
        long int id; 
        double salary_yr; //yearly pay 
        //double wk_hr_worked; //amount of hrs employee worked per wk
        double pay_hr; //pay per hourr 
        double biWk_hr_worked; //hrs worked for 2 weeks 
        double biWk_pay;  //pay per 2weeks
        
    public:
        employee(string nameE, long int idE, double biWk_hr_workedE = 0.0, double pay_hrE = 0.0)
        {
            name = nameE;
            id = idE;
            pay_hr = pay_hrE;
            biWk_hr_worked = biWk_hr_workedE; 
            //wk_hr_worked =  biWk_hr_worked/2;
            biWk_pay = 0; 
            salary_yr = 0;
        }

        //preCondition: biWk_hr_worked and pay_hr cant be negative
        //postcondition: will return the salary of the employee
        int yearly_salary(){
            biWk_pay = biWk_hr_worked * pay_hr; //pay per 2 weeks
            salary_yr = 26*biWk_pay; //26 biweekly checks per year
            return salary_yr;
        }

        //preCOndition:percent and salary_yr cant be negative 
        //postcondition: returns the new salary after the percent increase 
        int increase_salaryBy(double percent){
            double p = salary_yr * percent;
            salary_yr = salary_yr+p;
            return salary_yr;
        }

        //precondition: biWk_hr_worked cant be negative
        //postcondition: returns the amount of hours the employee worked overtime. 
        int overtime(){
            return (80 - biWk_hr_worked); //over 40 hr a week is overtime. doing 2 weeks. so over 80 hr is overtime
        }
       

}
