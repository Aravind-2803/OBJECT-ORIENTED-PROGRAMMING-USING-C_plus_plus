#include<iostream>
#include<conio.h>
using namespace std;
class employee
{
    protected:
        int employee_id;
        float salary;
    public:
        void set_value(int id,float sal)
        {
            this->employee_id=id;
            this->salary=sal;
        }

        int id(void)
        {
            return employee_id;
        }
        float sal()
        {
            return salary;
        }
};
class sports
{
    protected:
        string SportName;
    public:
        void set_name(string name)
        {
            this->SportName=name;
        }
    string name()
    {
        return SportName;
    }
};
class athlete: public employee,public sports
{
    public:
        void display()
        {
            cout<<"EMPLOYEE_ID="<<id()<<endl;

            cout<<"EMPLOYEE_SALARY="<<sal()<<endl;

            cout<<"EMPLOYEE_SPORTNAME="<<name()<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
    
        }

};
int main(){
    int n,id;
    float sal;
    string nam;
    cout<<"ENTER NUMBER OF EMPLOYEES"<<endl;
    cin>>n;
    athlete a[n];
    for(int i=0;i<n;i++)
    {
        cout<<"ENTER EMPLOYEE_ID="<<endl;
        cin>>id;
        cout<<"ENTER EMPLOYEE_SALARY="<<endl;
        cin>>sal;
        cout<<"ENTER EMPLOYEE_SPORTNAME="<<endl;
        cin>>nam;
        a[i].set_value(id,sal);
        a[i].set_name(nam);
    }
    
    for(int j=0;j<n;j++)
    {
        cout<<"EMPLOYEE"<<j+1<<endl;
        cout<<endl;
        cout<<endl;
        a[j].display();
    }
    
}
