#include <string>
#include <iostream>
#include <vector>
#include <exception>
#include <stdio.h>    
#include <stdlib.h> 
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Menu_Bar.H>

using namespace std;

class Robot_parts 
{
  public:
    Robot_parts(int p_count,
                string p_part_name,
                int p_part_number,
                int p_model_number,
                double p_weight,
                double p_cost,
                int p_battery_amount,
                int p_battery_compartment,
                double p_battery1_energy,
                double p_battery2_energy,
                double p_battery3_energy,
                double p_locomotor_speed,
                double p_locomotor_power,
                double p_arm_power1,
                double p_arm_power2,
                string p_model_name,
                string p_part_types,
                double p_price,
                string p_description) :

                count(p_count),
                part_name(p_part_name),
                part_number(p_part_number),
                model_number(p_model_number),
                weight(p_weight),
                cost(p_cost),
                battery_amount(p_battery_amount),
                battery_compartment(p_battery_compartment),
                battery1_energy(p_battery1_energy),
                battery2_energy(p_battery2_energy),
                battery3_energy(p_battery3_energy),
                locomotor_speed(p_locomotor_speed),
                locomotor_power(p_locomotor_power),
                arm_power1(p_arm_power1),
                arm_power2(p_arm_power2),
                model_name(p_model_name),
                part_types(p_part_types),
                price(p_price),
                description(p_description) { }

  protected:
    int count;
    string part_name;
    int part_number;
    int model_number;
    string model_name;
    double model_price;
    string part_types;
    double weight;
    double cost;
    double price;
    string description;

   private:
    int battery_amount;
    int battery_compartment;
    double battery1_energy;
    double battery2_energy;
    double battery3_energy;
    double locomotor_speed;
    double locomotor_power;
    double arm_power1;
    double arm_power2;
};


class Shop 
{
  public:
    void add_robot_model(Robot_parts robot)
    {
        robot_models.push_back(robot);
    }


    int number_of_models() 
    {
        return robot_models.size();
    }


  private:
    vector<Robot_parts> robot_models;

};



class View 
{
  public:
    View(Shop& s) : shop(s) { }

  private:
    Shop& shop;
};



class Controller
{
public:
    int count;
    int torso;
    int head;
    int arm;
    int locomotor;
    int battery;

  Controller (Shop& s, View& view) : shop(s), view(view) { }

  void print_model_info(int count)
    {
        int j;
        int i=0;
        string temp;

        while(i<count)
        {
            cout << std::to_string(i) << ") " << robot_model_name[i] << endl;
            i++;
        }

        cout << "\nEnter the number corresponding to the model name to see its parts: ";
        cin >> j;
        cout << robot_part_description[j] << endl;
        //printf("%s\n", robot_part_description[j].c_str());
    }

 void component(int& i)
 {
    int part_number, model_number, battery_amount, battery_compartment, type, j;
    string model_name, part_types, description, part_name, temp;
    double price, battery1_energy, battery2_energy, battery3_energy, locomotor_speed, locomotor_power, arm_power1, arm_power2, cost, weight, model_price, temp2, temp1;

    part_types = "";
    count = 0;
    torso = 0;
    head = 0;
    arm = 0;
    locomotor = 0;
    battery = 0;
    cost = 0.0;
    weight = 0.0;

    cout << "(1)Torso\n(2)Head\n(3)Arms\n(4)Locomotor\n(5)Battery\nEnter a number, 1 through 5, that indicates the part you are adding: ";
    cin >> type;
    cout << "Enter a name for the component: ";
    cin >> part_name;

    if (type == 1)
    {
            torso++;
            cin.ignore();
            cout << "Enter a description for this component: ";
            getline (cin,temp);
            cout << "Enter the component's part number: ";
            cin >> part_number;
            cout << "Enter the component's cost: ";
            cin >> temp2;
            cout << "Enter, from 1 to 3, how many battery compartments this torso has: ";
            cin >> battery_compartment;
            cout << "Enter the components weight: ";
            cin >> temp1;
            description = "Torso("+std::to_string(part_number)+") Info: "+temp+ " Weight: "+std::to_string(temp1)+" Cost: $"+std::to_string(temp2)+"\n";
            part_types = part_types + " " + description;
            weight = weight + temp1;
            cost = cost + temp2;
            cout << "\n";
    }
    

    if (type == 2)
    {
            head++;
            cin.ignore();
            cout << "Enter a description for this component: ";
            getline (cin,temp);
            cout << "Enter the component's part number: ";
            cin >> part_number;
            cout << "Enter the components weight: ";
            cin >> temp1;
            cout << "Enter the component's cost: ";
            cin >> temp2;
            description = "Head("+std::to_string(part_number)+") Info: "+temp+ " Weight: "+std::to_string(temp1)+" Cost: $"+std::to_string(temp2)+"\n";
            weight = weight + temp1;
            cost = cost + temp2;
            part_types = part_types + "," + description;
            cout << "\n";
    }

    if (type == 3)
    {
        int a;
        cout << "How many, from 1 to 2, arms are there: ";
        cin >> a;

            if (a == 2)
            {
                arm++;
                cin.ignore();
                cout << "Enter a description for Arm1: ";
                getline (cin,temp);
                cout << "Enter Arm1's part number: ";
                cin >> part_number;
                cout << "Enter the component's cost: ";
                cin >> temp2;
                cout << "Enter Arm1's power consumption in watts: ";
                cin >> arm_power1;
                cout << "Enter Arm1's weight: ";
                cin >> temp1;
                description = "Arm1("+std::to_string(part_number)+") Info: "+temp+ " Weight: "+std::to_string(temp1)+" Cost: $"+std::to_string(temp2)+"\n";
                weight = weight + temp1;
                cost = cost + temp2;
                part_types = part_types + "," + description;
                cout << "\n";


                cin.ignore();
                cout << "Enter a description for Arm2: ";
                getline (cin,temp);
                cout << "Enter Arm2's part number: ";
                cin >> part_number;
                cout << "Enter the component's cost: ";
                cin >> temp1;
                cost = cost + temp1;
                cout << "Enter Arm2's power consumption in watts: ";
                cin >> arm_power1;
                cout << "Enter Arm2's weight: ";
                cin >> temp1;
                weight = weight + temp1;
                description = "Arm2("+std::to_string(part_number)+") Info: "+temp+ " Weight: "+std::to_string(temp1)+" Cost: $"+std::to_string(temp2)+"\n";
                weight = weight + temp1;
                cost = cost + temp2;
                part_types = part_types + "," + description;
                cout << "\n";
            }

            if (a == 1)
            {
                arm++;
                cin.ignore();
                cout << "Enter a description for this Arm: ";
                getline (cin,temp);
                cout << "Enter the Arm's part number: ";
                cin >> part_number;
                cout << "Enter the component's cost: ";
                cin >> temp1;
                cost = cost + temp1;
                cout << "Enter the Arm's power consumption in watts: ";
                cin >> arm_power1;
                cout << "Enter the Arm's weight: ";
                cin >> temp1;
                weight = weight + temp1;
                description = "Arm("+std::to_string(part_number)+") Info: "+temp+ " Weight: "+std::to_string(temp1)+" Cost: $"+std::to_string(temp2)+"\n";
                weight = weight + temp1;
                cost = cost + temp2;
                part_types = part_types + "," + description;
                cout << "\n";
            }
    }

    if (type == 4)
    {
            locomotor++;
            cin.ignore();
            cout << "Enter a description for this component: ";
            getline (cin,temp);
            cout << "Enter the component's part number: ";
            cin >> part_number;
            cout << "Enter the component's cost: ";
            cin >> temp2;
            cout << "Enter the locomotor's maximum speed in MPH: ";
            cin >> locomotor_speed;
            cout << "Enter the locomotor's power consumption in watts: ";
            cin >> locomotor_power;
            cout << "Enter the component's weight: ";
            cin >> temp1;
            description = "Locomotor("+std::to_string(part_number)+") Info: "+temp+ " Weight: "+std::to_string(temp1)+" Cost: $"+std::to_string(temp2)+"\n";
            weight = weight + temp1;
            cost = cost + temp2;
            part_types = part_types + "," + description;
            cout << "\n";
    }

    if (type == 5)
    {

            cout << "Enter how many, from 1 to 3, batteries there are: ";
            cin >> battery_amount;
            j=0;

        while(j < battery_amount)
        {   
            cout << "Enter the energy, in kilowatt hours, of battery " << j+1 << ": ";
            if (j == 0)
            {
                cin >> battery1_energy;
            }
            if (j == 1 && battery_amount >= 1)
            {
                cin >> battery2_energy;
            }
            if (j == 2)
            {
                cin >> battery3_energy;
            }
            j++;
        }

            if (battery_amount == 3)
            {
                battery++;
                cin.ignore();
                cout << "Enter a description for Battery1: ";
                getline (cin,temp);
                cout << "Enter the component's part number: ";
                cin >> part_number;
                cout << "Enter the component's cost: ";
                cin >> temp2;
                cout << "Enter the component's weight: ";
                cin >> temp1;
                description = "Battery1("+std::to_string(part_number)+") Info: "+temp+ " Weight: "+std::to_string(temp1)+" Cost: $"+std::to_string(temp2)+"\n";
                weight = weight + temp1;
                cost = cost + temp2;
                part_types = part_types + "," + description;
                cout << "\n";

                cin.ignore();
                cout << "Enter a description for Battery2: ";
                getline (cin,temp);
                cout << "Enter the component's part number: ";
                cin >> part_number;
                cout << "Enter the component's cost: ";
                cin >> temp2;
                cout << "Enter the component's weight: ";
                cin >> temp1;             
                description = "Battery2("+std::to_string(part_number)+") Info: "+temp+ " Weight: "+std::to_string(temp1)+" Cost: $"+std::to_string(temp2)+"\n";
                weight = weight + temp1;
                cost = cost + temp2;
                part_types = part_types + "," + description;
                cout << "\n";

                cin.ignore();
                cout << "Enter a description for Battery3: ";
                getline (cin,temp);
                cout << "Enter the component's part number: ";
                cin >> part_number;
                cout << "Enter the component's cost: ";
                cin >> temp2;
                cout << "Enter the component's weight: ";
                cin >> temp1;
                description = "Battery1("+std::to_string(part_number)+") Info: "+temp+ " Weight: "+std::to_string(temp1)+" Cost: $"+std::to_string(temp2)+"\n";
                weight = weight + temp1;
                cost = cost + temp2;
                part_types = part_types + "," + description;
                cout << "\n";
            }
            if (battery_amount == 2)
            {
                battery++;
                cin.ignore();
                cout << "Enter a description for Battery1: ";
                getline (cin,temp);
                cout << "Enter the component's part number: ";
                cin >> part_number;
                cout << "Enter the component's cost: ";
                cin >> temp2;
                cout << "Enter the component's weight: ";
                cin >> temp1;
                description = "Battery1("+std::to_string(part_number)+") Info: "+temp+ " Weight: "+std::to_string(temp1)+" Cost: $"+std::to_string(temp2)+"\n";
                weight = weight + temp1;
                cost = cost + temp2;
                part_types = part_types + "," + description;
                cout << "\n";

                cin.ignore();
                cout << "Enter a description for Battery2: ";
                getline (cin,temp);
                cout << "Enter the component's part number: ";
                cin >> part_number;
                cout << "Enter the component's cost: ";
                cin >> temp2;
                cout << "Enter the component's weight: ";
                cin >> temp1;             
                description = "Battery2("+std::to_string(part_number)+") Info: "+temp+ " Weight: "+std::to_string(temp1)+" Cost: $"+std::to_string(temp2)+"\n";
                weight = weight + temp1;
                cost = cost + temp2;
                part_types = part_types + "," + description;
                cout << "\n";
            }
            if (battery_amount == 1)
            {
                battery++;
                cin.ignore();
                cout << "Enter a description for the Battery: ";
                getline (cin,temp);
                cout << "Enter the component's part number: ";
                cin >> part_number;
                cout << "Enter the component's cost: ";
                cin >> temp2;
                cout << "Enter the component's weight: ";
                cin >> temp1;
                description = "Battery("+std::to_string(part_number)+") Info: "+temp+ " Weight: "+std::to_string(temp1)+" Cost: $"+std::to_string(temp2)+"\n";
                weight = weight + temp1;
                cost = cost + temp2;
                part_types = part_types + "," + description;
                cout << "\n";
            }
    }
    

           cout << "Enter (0) if you are done with this model or enter (1) if you need to add another component: ";
           cin >> i;
           cout << "\n";

            if (i == 0)
            {
            cin.ignore();
            cout << "Enter this model's name: ";
            getline (cin,model_name);
            cout << "\n";

            cout << "Enter this model's number: ";
            cin >> model_number;
            cout << "\n";

            cout << "The current cost of this model is $" << cost << ". Enter this model's price: ";
            cin >> price;
            cout << "\n";

            count++;
            robot_part_description.push_back(part_types);
            robot_model_name.push_back(model_name);

            /*shop.add_robot_model(Robot_parts(count,
                part_name,
                part_number,
                model_number,
                weight,
                cost,
                battery_amount,
                battery_compartment,
                battery1_energy,
                battery2_energy,
                battery3_energy,
                locomotor_speed,
                locomotor_power,
                arm_power1,
                arm_power2,
                model_name,
                part_types,
                price,
                description));*/
            }    
 }


  void execute_cmd()
  {
    int cmd, cmd1;
    int i = 1;
    int j = 1;

    while(i != 0)
    {
     cout << "1)Create Robot Model\n2)Print Robot Model Parts\n0)Exit\nEnter a number the number that indicates what you are trying to do: ";
     cin >> cmd;
     cout << "\n";

     if(cmd == 1)
     {
        while(j != 0)
        {
            component(j);
        }
     }
     if(cmd == 2)
     {
        print_model_info(count);
     }
     if(cmd == 0)
     {
        i = 0;
     }
    }
  }

  private:
    Shop& shop;
    View& view;
    vector<string> robot_part_description;
    vector<string> robot_model_name;
};


int main() 
{
cout << "-------------------Welcome to the Robbie Robot Shop!-------------------\n\n";

Shop shop;
View view(shop);
Controller controller(shop, view);

controller.execute_cmd();

return 0;
}

