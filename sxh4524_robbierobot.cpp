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
    Robot_parts(string p_part_name,
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





class RobotPart
{    
private:
        std::string this_name;
        int this_partNumber;
        double this_weight;
        double this_cost;
        string this_description;
        int this_partType;          //0=head; 1=chest; 2=arm; 3=locomotor; 4=battery

    public:
        RobotPart(std::string name, int partNum, double weight, double cost, std::string description, int type)
            : this_name(name), this_partNumber(partNum), this_weight(weight), this_cost(cost), this_description(description),
            this_partType(type) { }

        string getName() 
        {
            return this_name;
        }

        int getPartNumber() 
        {
            return this_partNumber;
        }

        int getPartType() 
        {                  //0=head; 1=chest; 2=arm; 3=locomotor; 4=battery
            return this_partType;
        }

        double getWeight() 
        {
            return this_weight;
        }

        double getCost() 
        {
            return this_cost;
        }

        string getDescription() 
        {
            return this_description;
        }

};





class Controller
{
public:

    int torso;
    int head;
    int arm;
    int locomotor;
    int battery;

  Controller (Shop& s, View& view) : shop(s), view(view) { }

  void get_model_info()
    {
        int i = 1;

    	while(i != 0)
    	{
            component(i);
    	}
    }



 void component(int& i)
 {
    int part_number, model_number, battery_amount, battery_compartment, temp1, type, j;
    string model_name, part_types, description, part_name, temp;
    double price, battery1_energy, battery2_energy, battery3_energy, locomotor_speed, locomotor_power, arm_power1, arm_power2, cost, weight, model_price;

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
            cout << "Enter a description for this component:\n";
            cin >> temp;
            cout << "Enter the component's part number: ";
            cin >> part_number;
            cout << "Enter the component's cost: ";
            cin >> temp1;
            cost = cost + temp1;
            cout << "Enter, from 1 to 3, how many battery compartments this torso has: ";
            cin >> battery_compartment;
            cout << "Enter the components weight: ";
            cin >> temp1;
            weight = weight + temp1;
            description = "Torso("+to_string(part_number)+"): "+ temp + "\n";
            part_types = part_types + "," + description;
            cout << "\n";
    }

    if (type == 2)
    {
            head++;
            cout << "Enter a description for this component:\n";
            cin >> temp;
            cout << "Enter the component's part number: ";
            cin >> part_number;
            cout << "Enter the components weight: ";
            cin >> temp1;
            weight = weight + temp1;
            cout << "Enter the component's cost: ";
            cin >> temp1;
            cost = cost + temp1;
            description = "Head("+std::to_string(part_number)+"): "+ temp + "\n";
            part_types = part_types + "," + description;
    }

    if (type == 3)
    {
        int a;
        cout << "How many, from 1 to 2, arms are there: ";
        cin >> a;

            if (a == 2)
            {
                arm++;
                cout << "Enter a description for Arm1:\n";
                cin >> temp;
                cout << "Enter Arm1's part number: ";
                cin >> part_number;
                cout << "Enter the component's cost: ";
                cin >> temp1;
                cost = cost + temp1;
                cout << "Enter Arm1's power consumption in watts: ";
                cin >> arm_power1;
                cout << "Enter Arm1's weight: ";
                cin >> temp1;
                weight = weight + temp1;
                cout << "Enter Arm1's part number: ";
                cin >> part_number;
                description = "Arm1("+std::to_string(part_number)+"): "+ temp + "\n";
                part_types = part_types + "," + description;


                cout << "Enter a description for Arm2:\n";
                cin >> temp;
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
                cout << "Enter Arm2's part number: ";
                cin >> part_number;
                description = "Arm2("+std::to_string(part_number)+"): "+ temp + "\n";
                part_types = part_types + "," + description;

                cout << "\n";
            }
            if (arm == 1)
            {
                arm++;
                cout << "Enter a description of Arm:\n";
                cin >> temp;
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
                cout << "Enter the Arm's part number: ";
                cin >> part_number;
                description = "Arm("+std::to_string(part_number)+"): "+ temp + "\n";
                part_types = part_types + "," + description;
            }
    }

    if (type == 4)
    {
            locomotor++;
            cout << "Enter a description of this component:\n";
            cin >> temp;
            cout << "Enter the component's part number: ";
            cin >> part_number;
            cout << "Enter the component's cost: ";
            cin >> temp1;
            cost = cost + temp1;
            cout << "Enter the locomotor's maximum speed in MPH: ";
            cin >> locomotor_speed;
            cout << "Enter the locomotor's power consumption in watts: ";
            cin >> locomotor_power;
            cout << "Enter the component's weight: ";
            cin >> temp1;
            weight = weight + temp1;
            description = "Torso("+std::to_string(part_number)+"): "+ temp + "\n";
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
                cout << "Enter a description for Battery1:\n";
                cin >> temp;
                cout << "Enter the component's part number: ";
                cin >> part_number;
                cout << "Enter the component's cost: ";
                cin >> temp1;
                cost = cost + temp1;
                cout << "Enter the component's weight: ";
                cin >> temp1;
                weight = weight + temp1;
                cout << "Enter a description for Battery1:\n";
                cin >> temp;
                description = "Battery1("+std::to_string(part_number)+"): "+ temp + "\n";
                part_types = part_types + "," + description;
                cout << "\n";

                cout << "Enter a description for Battery2:\n";
                cin >> temp;
                cout << "Enter the component's part number: ";
                cin >> part_number;
                cout << "Enter the component's cost: ";
                cin >> temp1;
                cost = cost + temp1;
                cout << "Enter the component's weight: ";
                cin >> temp1;
                weight = weight + temp1;
                cout << "Enter a description for Battery2:\n";
                cin >> temp;
                description = "Battery2("+std::to_string(part_number)+"): "+ temp + "\n";
                part_types = part_types + "," + description;
                cout << "\n";


  
                cout << "Enter a description for Battery3:\n";
                cin >> temp;
                cout << "Enter the component's part number: ";
                cin >> part_number;
                cout << "Enter the component's cost: ";
                cin >> temp1;
                cost = cost + temp1;
                cout << "Enter the component's weight: ";
                cin >> temp1;
                weight = weight + temp1;
                cout << "Enter a description for Battery3:\n";
                cin >> temp;
                description = "Battery3("+std::to_string(part_number)+"): "+ temp + "\n";
                part_types = part_types + "," + description;

                cout << "\n";
            }
            else if (battery_amount == 2)
            {
                battery++;
                cout << "Enter a description for Battery1:\n";
                cin >> temp;
                cout << "Enter the component's part number: ";
                cin >> part_number;
                cout << "Enter the component's cost: ";
                cin >> temp1;
                cost = cost + temp1;
                cout << "Enter the component's weight: ";
                cin >> temp1;
                weight = weight + temp1;
                cout << "Enter a description for Battery1:\n";
                cin >> temp;
                description = "Battery1("+std::to_string(part_number)+"): "+ temp + "\n";
                part_types = part_types + "," + description;
                cout << "\n";

                cout << "Enter a description for Battery2:\n";
                cin >> temp;
                cout << "Enter the component's part number: ";
                cin >> part_number;
                cout << "Enter the component's cost: ";
                cin >> temp1;
                cost = cost + temp1;
                cout << "Enter the component's weight: ";
                cin >> temp1;
                weight = weight + temp1;
                cout << "Enter a description for Battery2:\n";
                cin >> temp;
                description = "Battery2("+std::to_string(part_number)+"): "+ temp + "\n";
                part_types = part_types + "," + description;

                cout << "\n";
            }
            else if (battery_amount == 1)
            {
                battery++;
                cout << "Enter a description for the Battery:\n";
                cin >> temp;
                cout << "Enter the component's part number: ";
                cin >> part_number;
                cout << "Enter the component's cost: ";
                cin >> temp1;
                cost = cost + temp1;
                cout << "Enter the component's weight: ";
                cin >> temp1;
                weight = weight + temp1;
                cout << "Enter a description for the Battery:\n";
                cin >> temp;
                description = "Battery("+std::to_string(part_number)+"): "+ temp + "\n";
                part_types = part_types + "," + description;

                cout << "\n";
            }
    }

           cout << "Enter (0) if you are done with this model or enter (1) if you need to add another component: ";
           cin >> i;
           cout << "\n";

            if (i == 0)
            {
            cout << "Enter this model's name: ";
            cin >> model_name;
            cout << "\n";

            cout << "Enter this model's number: ";
            cin >> model_number;
            cout << "\n";

            cout << "The current cost of this model is $" << cost << ". Enter this model's price: ";
            cin >> price;
            cout << "\n";

            shop.add_robot_model(Robot_parts(part_name,
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
                description));
            }    
 }

  void execute_cmd()
  {
  	int cmd, cmd1;
  	int i = 1;

  	while(i != 0)
  	{
  	 cout << "1)Create Robot Model\n2)Print Robot Model Parts0)Exit\nEnter a number the number that indicates what you are trying to do: ";
  	 cin >> cmd;
  	 cout << "\n";

  	 if(cmd == 1)
  	 {
  	 	get_model_info();
  	 }
     if(cmd == 2)
     {
        get_model_info();
     }
     if(cmd == 0)
     {
        i = 0;
     }
  	 else
  	 {
  		cout << "Unavailable, returning to main menu." << endl;
  	 }
    }
  }

  private:
    Shop& shop;
    View& view;
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



