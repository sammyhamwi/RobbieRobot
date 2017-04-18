///////////////////////////////////////////////////////////////////////////////////////////////
///////// Compile using command line "fltk-config --compile sxh4524_robbierobot.cpp" //////////
//////////// Then use command line "./sxh4524_robbierobot" to run the application /////////////
///////////////////////////////////////////////////////////////////////////////////////////////

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <exception>
#include <stdio.h>    
#include <stdlib.h> 
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Menu_Bar.H>

using namespace std;

class Controller
{
public:
    int count, count1, count2;
    string part_types;
    int torso;
    int head;
    int arm;
    int locomotor;
    int battery;
    double cost;
    double weight;

  void print_model_info(int count)
    {
        int j;
        int i=0;
        string temp, tempp;

        while(i<count)
        {
            temp = temp + std::to_string(i) + ") " + robot_model_name[i] + "\n";
            i++;
        }

        tempp = fl_input("%s\nEnter the number corresponding to the model name to see its parts: ","", temp.c_str());
        stringstream(tempp) >> j;
        fl_message("%s\n",robot_part_description[j].c_str());
    }


 void new_sa()
 {
    string name, emplo_num, temp;
    cin.ignore();
    cout << "Enter the the sales associate's name: ";
    getline (cin, name);
    cout << "Enter the the sales associate's employee number: ";
    cin >> emplo_num;

    temp = "Name: "+name+" Employee Number: "+emplo_num;
    sale_associate.push_back(temp);
    count1++;
 }


 void new_bc()
 {
    string name, cust_num, phone_num, email, temp;
    cin.ignore();
    cout << "Enter the the customers name: ";
    getline (cin, name);
    cout << "Enter the the customer number for this new customer: ";
    cin >> cust_num;
    cout << "Enter the customer's phone number: ";
    cin >> phone_num;
    cout << "Enter the customer's email: ";
    cin >> email;

    temp = "Name: "+name+" Customer Number: "+cust_num+" Phone: "+phone_num+" Email: "+email;
    beloved_customer.push_back(temp);
    count2++;
 }

 void print_sa(int count1)
 {
    int i=0;

    while(i<count1)
    {
        cout << std::to_string(i) << ") " << sale_associate[i] << endl;
        i++;
    }
 }

 void print_bc(int count2)
 {
    int i=0;

    while(i<count2)
    {
        cout << std::to_string(i) << ") " << beloved_customer[i] << endl;
        i++;
    }
 }

 void sell_robot(int count, int count2)
 {
    int h, j, k;
    int i=0;
    string temp;

    cout << "\n\n";
    print_sa(count1);
    cout << "\nEnter the corresponding number to the sale's associate you are: ";
    cin >> h;



    while(i<count)
    {
        cout << std::to_string(i) << ") " << robot_model_name[i] << "\n" << robot_part_description[i] << "\n\n";
        i++;
    }

    i = 0;

    cout << "\nEnter the corresponding number to the model you are selling: ";
    cin >> j;

    while(i<count2)
    {
        cout << std::to_string(i) << ") " << beloved_customer[i] << endl;
        i++;
    }

    cout << "\nEnter the corresponding number to the customer you are selling the model to: ";
    cin >> k;

    beloved_customer[k] = beloved_customer[k] + " Bought Robot Model: "+robot_model_name[j];

 }



 void component(int& i)
 {
    int part_number, model_number, battery_amount, battery_compartment, type, j;
    string model_name, description, part_name, price, temp, tempp;
    double battery1_energy, battery2_energy, battery3_energy, locomotor_speed, locomotor_power, arm_power1, arm_power2, model_price, temp2, temp1;

    torso = 0;
    head = 0;
    arm = 0;
    locomotor = 0;
    battery = 0;

    tempp = fl_input("(1)Torso\n(2)Head\n(3)Arms\n(4)Locomotor\n(5)Battery\nEnter a number, 1 through 5, that indicates the part you are adding: ");
    stringstream(tempp) >> type;
    part_name = fl_input("Enter a name for the component: ");

    if (type == 1)
    {
            torso++;
            tempp = fl_input("Enter the component's part number: ");
            stringstream(tempp) >> part_number;
            temp = fl_input("Enter a description for this component: ");
            tempp = fl_input("Enter the component's cost: ");
            stringstream(tempp) >> temp2;
            tempp = fl_input("Enter, from 1 to 3, how many battery compartments this torso has: ");
            stringstream(tempp) >> battery_compartment;
            tempp = fl_input("Enter the components weight: ");
            stringstream(tempp) >> temp1;
            description = "Torso("+std::to_string(part_number)+") Description: "+temp+ " Weight: "+std::to_string(temp1)+" Cost: $"+std::to_string(temp2)+"\n";
            part_types = part_types + "" + description;
            weight = weight + temp1;
            cost = cost + temp2;
    }
    

    if (type == 2)
    {
            head++;
            tempp = fl_input("Enter the component's part number: ");
            stringstream(tempp) >> part_number;
            temp = fl_input("Enter a description for this component: ");
            tempp = fl_input("Enter the components weight: ");
            stringstream(tempp) >> temp1;
            tempp = fl_input("Enter the component's cost: ");
            stringstream(tempp) >> temp2;
            description = "Head("+std::to_string(part_number)+") Description: "+temp+ " Weight: "+std::to_string(temp1)+" Cost: $"+std::to_string(temp2)+"\n";
            weight = weight + temp1;
            cost = cost + temp2;
            part_types = part_types + "" + description;
    }

    if (type == 3)
    {
        int a;
        tempp = fl_input("How many, from 1 to 2, arms are there: ");
        stringstream(tempp) >> a;
        cin >> a;

            if (a == 2)
            {
                arm++;           
                tempp = fl_input("Enter Arm1's part number: ");
                stringstream(tempp) >> part_number;
                temp = fl_input("Enter a description for Arm1: ");
                tempp = fl_input("Enter the component's cost: ");
                stringstream(tempp) >> temp2;
                tempp = fl_input("Enter Arm1's power consumption in watts: ");
                stringstream(tempp) >> arm_power1;
                tempp = fl_input("Enter Arm1's weight: ");
                stringstream(tempp) >> temp1;
                description = "Arm1("+std::to_string(part_number)+") Description: "+temp+ " Weight: "+std::to_string(temp1)+" Cost: $"+std::to_string(temp2)+"\n";
                weight = weight + temp1;
                cost = cost + temp2;
                part_types = part_types + "" + description;


                tempp = fl_input("Enter Arm2's part number: ");
                stringstream(tempp) >> part_number;
                temp = fl_input("Enter a description for Arm2: ");
                tempp = fl_input("Enter the component's cost: ");
                stringstream(tempp) >> temp2;
                tempp = fl_input("Enter Arm2's power consumption in watts: ");
                stringstream(tempp) >> arm_power1;
                tempp = fl_input("Enter Arm2's weight: ");
                stringstream(tempp) >> temp1;
                description = "Arm2("+std::to_string(part_number)+") Description: "+temp+ " Weight: "+std::to_string(temp1)+" Cost: $"+std::to_string(temp2)+"\n";
                weight = weight + temp1;
                cost = cost + temp2;
                part_types = part_types + "" + description;
            }

            if (a == 1)
            {
                arm++;
                tempp = fl_input("Enter the Arm's part number: ");
                stringstream(tempp) >> part_number;
                temp = fl_input("Enter a description for the Arm: ");
                tempp = fl_input("Enter the Arm's cost: ");
                stringstream(tempp) >> temp2;
                tempp = fl_input("Enter the Arm's power consumption in watts: ");
                stringstream(tempp) >> arm_power1;
                tempp = fl_input("Enter the Arm's weight: ");
                stringstream(tempp) >> temp1;
                description = "Arm("+std::to_string(part_number)+") Description: "+temp+ " Weight: "+std::to_string(temp1)+" Cost: $"+std::to_string(temp2)+"\n";
                weight = weight + temp1;
                cost = cost + temp2;
                part_types = part_types + "" + description;
            }
    }

    if (type == 4)
    {
            locomotor++;
            tempp = fl_input("Enter the component's part number: ");
            stringstream(tempp) >> part_number;
            temp = fl_input("Enter a description for this component: ");
            tempp = fl_input("Enter the component's cost: ");
            stringstream(tempp) >> temp2;
            tempp = fl_input("Enter the locomotor's maximum speed in MPH: ");
            stringstream(tempp) >> locomotor_speed;
            tempp = fl_input("Enter the locomotor's power consumption in watts: ");
            stringstream(tempp) >> locomotor_power;
            tempp = fl_input("Enter the components weight: ");
            stringstream(tempp) >> temp1;
            description = "Locomotor("+std::to_string(part_number)+") Description: "+temp+ " Weight: "+std::to_string(temp1)+" Cost: $"+std::to_string(temp2)+"\n";
            weight = weight + temp1;
            cost = cost + temp2;
            part_types = part_types + "" + description;
    }

    if (type == 5)
    {

            tempp = fl_input("Enter how many, from 1 to 3, batteries there are: ");
            stringstream(tempp) >> battery_amount;
            j=0;

        while(j < battery_amount)
        {   
            if (j == 0)
            {
                tempp = fl_input("Enter the energy, in kilowatt hours, of battery 1: ");
                stringstream(tempp) >> battery1_energy;

            }
            if (j == 1 && battery_amount >= 1)
            {
                tempp = fl_input("Enter the energy, in kilowatt hours, of battery 2: ");
                stringstream(tempp) >> battery1_energy;
            }
            if (j == 2)
            {
                tempp = fl_input("Enter the energy, in kilowatt hours, of battery 3: ");
                stringstream(tempp) >> battery1_energy;
            }
            j++;
        }

            if (battery_amount == 3)
            {
                battery++;
                tempp = fl_input("Enter Battery1's part number: ");
                stringstream(tempp) >> part_number;
                temp = fl_input("Enter a description for Battery1: ");
                tempp = fl_input("Enter Battery1's cost: ");
                stringstream(tempp) >> temp2;
                tempp = fl_input("Enter Battery1's weight: ");
                stringstream(tempp) >> temp1;
                description = "Battery1("+std::to_string(part_number)+") Description: "+temp+ " Weight: "+std::to_string(temp1)+" Cost: $"+std::to_string(temp2)+"\n";
                weight = weight + temp1;
                cost = cost + temp2;
                part_types = part_types + "" + description;

                tempp = fl_input("Enter Battery2's part number: ");
                stringstream(tempp) >> part_number;
                temp = fl_input("Enter a description for Battery2: ");
                tempp = fl_input("Enter Battery2's cost: ");
                stringstream(tempp) >> temp2;
                tempp = fl_input("Enter Battery2's weight: ");
                stringstream(tempp) >> temp1;
                description = "Battery2("+std::to_string(part_number)+") Description: "+temp+ " Weight: "+std::to_string(temp1)+" Cost: $"+std::to_string(temp2)+"\n";
                weight = weight + temp1;
                cost = cost + temp2;
                part_types = part_types + "" + description;

                tempp = fl_input("Enter Battery3's part number: ");
                stringstream(tempp) >> part_number;
                temp = fl_input("Enter a description for Battery3: ");
                tempp = fl_input("Enter Battery3's cost: ");
                stringstream(tempp) >> temp2;
                tempp = fl_input("Enter Battery3's weight: ");
                stringstream(tempp) >> temp1;
                description = "Battery3("+std::to_string(part_number)+") Description: "+temp+ " Weight: "+std::to_string(temp1)+" Cost: $"+std::to_string(temp2)+"\n";
                weight = weight + temp1;
                cost = cost + temp2;
                part_types = part_types + "" + description;
            }
            if (battery_amount == 2)
            {
                battery++;
                tempp = fl_input("Enter Battery1's part number: ");
                stringstream(tempp) >> part_number;
                temp = fl_input("Enter a description for Battery1: ");
                tempp = fl_input("Enter Battery1's cost: ");
                stringstream(tempp) >> temp2;
                tempp = fl_input("Enter Battery1's weight: ");
                stringstream(tempp) >> temp1;
                description = "Battery1("+std::to_string(part_number)+") Description: "+temp+ " Weight: "+std::to_string(temp1)+" Cost: $"+std::to_string(temp2)+"\n";
                weight = weight + temp1;
                cost = cost + temp2;
                part_types = part_types + "" + description;

                tempp = fl_input("Enter Battery2's part number: ");
                stringstream(tempp) >> part_number;
                temp = fl_input("Enter a description for Battery2: ");
                tempp = fl_input("Enter Battery2's cost: ");
                stringstream(tempp) >> temp2;
                tempp = fl_input("Enter Battery2's weight: ");
                stringstream(tempp) >> temp1;
                description = "Battery2("+std::to_string(part_number)+") Description: "+temp+ " Weight: "+std::to_string(temp1)+" Cost: $"+std::to_string(temp2)+"\n";
                weight = weight + temp1;
                cost = cost + temp2;
                part_types = part_types + "" + description;
            }
            if (battery_amount == 1)
            {
                battery++;
                tempp = fl_input("Enter the component's part number: ");
                stringstream(tempp) >> part_number;
                temp = fl_input("Enter a description for the Battery: ");
                tempp = fl_input("Enter the component's cost: ");
                stringstream(tempp) >> temp2;
                tempp = fl_input("Enter the component's weight: ");
                stringstream(tempp) >> temp1;
                description = "Battery("+std::to_string(part_number)+") Description: "+temp+ " Weight: "+std::to_string(temp1)+" Cost: $"+std::to_string(temp2)+"\n";
                weight = weight + temp1;
                cost = cost + temp2;
                part_types = part_types + "" + description;
            }
    }
    

           tempp = fl_input("Enter (0) if you are done with this model or enter (1) if you need to add another component: ");
           stringstream(tempp) >> i;

            if (i == 0)
            {
            model_name = fl_input("Enter this model's name: ");

            tempp = fl_input("Enter this model's number: ");
            stringstream(tempp) >> model_number;

            //price = fl_input("The current cost of this model is $"+std::to_string(cost)+". Enter this model's price: ");
            price = fl_input("The current cost of this model is $%f. Enter this model's price: ","",cost);

            count++;
            robot_part_description.push_back(part_types);
            robot_model_name.push_back(model_name);

            robot_model_name[count-1] = robot_model_name[count-1] + " Price: $"+price;
            }    
 }


  void execute_cmd()
  {
    string temp;
    int cmd, cmd1, j;
    int i = 1;
    count = 0;
    count1 = 0;
    count2 = 0;

    while(i != 0)
    {
     j = 1;
     //temp = fl_input("1)Create Robot Model\n2)Print Robot Model Parts\n3)Beloved Customer Menu\n4)Sales Associate Menu\n0)Exit\nEnter a number the number that indicates what you are trying to do: ");
     //stringstream(temp) >> cmd;
     temp = fl_input("1)Create Robot Model\n2)Print Robot Model Parts\n0)Exit\nEnter a number the number that indicates what you are trying to do: ");
     stringstream(temp) >> cmd;


     if(cmd == 1)
     {
        cost = 0.0;
        weight = 0.0;
        part_types = "";
        while(j != 0)
        {
            component(j);
        }
     }
     if(cmd == 2)
     {
        print_model_info(count);
     }
     /*if(cmd == 3)
     {
        temp = fl_input("1)Create Beloved Customer\n2)Print Beloved Customer's\nEnter a number the number that indicates what you are trying to do: ");
        stringstream(temp) >> cmd1;
        if(cmd1 == 1)
        {
            new_bc();
        }
        if(cmd1 == 2)
        {
            cout << "\n\n------------------Beloved Customers------------------\n";
            print_bc(count2);
        }
     }
     if(cmd == 4)
     {
        temp = fl_input("1)Create Sales Associate\n2)Print Sales Associate's\n3)Sell Robot Model to Customer\nEnter a number the number that indicates what you are trying to do: ");
        stringstream(temp) >> cmd1;
        if(cmd1 == 1)
        {
            new_sa();
        }
        if(cmd1 == 2)
        {
            cout << "\n\n------------------Sale Associate's------------------\n";
            print_sa(count1);
        }
        if(cmd1 == 3)
        {
            sell_robot(count, count2);
        }
     }*/
     if(cmd == 0)
     {
        i = 0;
     }
    }
  }

  private:
    vector<string> robot_part_description;
    vector<string> robot_model_name;
    vector<string> beloved_customer;
    vector<string> sale_associate;
};


int main() 
{
cout << "-------------------Welcome to the Robbie Robot Shop!-------------------\n\n";

Controller controller;

controller.execute_cmd();

return 0;
}
