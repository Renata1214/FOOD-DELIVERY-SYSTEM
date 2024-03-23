# FOOD-DELIVERY-SYSTEM

## INTRODUCTION

In today's fast-paced digital age, the convenience of ordering food online has become an integral part of modern life. In response to the burgeoning demand for this convenience, I have developed a comprehensive food delivery system. This system is meticulously designed to provide users with an efficient platform for ordering from their favorite restaurants, all within a single, user-friendly interface.

Drawing inspiration from the successful strategies employed by companies like Talabat, my food delivery system takes into account the varying delivery capacities of different restaurants. This approach allows for the optimization of available drivers to ensure efficient order processing.

While my program shares similarities with other food ordering apps, it distinguishes itself through a unique approach that emphasizes the interdependence between delivery personnel and the restaurants they serve. In this system, each restaurant manages its own dedicated fleet of delivery staff, with the number of personnel determined by their order demand. This approach minimizes the total number of hired individuals, fostering improved working conditions, including higher wages. It also concentrates the restaurant's economic resources within a smaller group of employees, resulting in a more efficient and streamlined operation.

Furthermore, this unique approach enhances the system's overall efficiency. By allowing each restaurant to have dedicated delivery personnel, we can finely tune the allocation of drivers, ensuring that orders are fulfilled promptly and reliably. This benefits not only the restaurant staff but also results in shorter waiting times and heightened customer satisfaction.

To ensure timely and reliable deliveries, the system performs a crucial check: it assesses the current availability of drivers at the selected restaurant. If there are enough drivers to handle the order, the system accepts the request and assigns the most suitable driver to the customer's location. The assignment is based on a calculated distance between the restaurant and available drivers. This calculation takes into account the driver's return journey from their current location to the restaurant, the pickup of the order, and the subsequent delivery to the customer, all in the most efficient and timely manner.

In the realm of software optimization, where the efficient allocation of memory resources is as vital as the optimization of physical resources, the system prioritizes memory efficiency. This is achieved through the meticulous application of Object-Oriented Programming (OOP) concepts. By employing classes and fostering interconnected relationships between different classes and functions, the system minimizes repetitive processes, resulting in significant improvements in program runtime.

In the upcoming sections of this report, we will delve deeper into the project's architecture, and implementation.

## Code Overview

In the main CPP file, the food delivery system begins to take shape. The program starts by providing the user with a menu where they can select either Restaurant A or Restaurant B. It uses a switch statement to handle the user's choice. Depending on the user's choice (1 for Restaurant A or 2 for Restaurant B), the program initializes specific parameters for the chosen restaurant. These parameters include the restaurant's menu items and prices, the number of available delivery drivers, the delivery fee, and the restaurant's name.

Afterward, a secondary function named Ordering Food Restaurant is called. This function is responsible for creating the necessary objects from each outlined class and calling the required member functions for the program to process the customer's order and organize the delivery of the order.

The Ordering Food Restaurant function begins by using the previously initialized parameters to create an instance of the Business class. This action implicitly also creates an object of the Customer class, an object of the ID Data class, and a series of objects of the Delivery People class, which, as explained before, are saved in a vector belonging to the object of the Business class. Subsequently, the restaurant's menu is printed using the PrintMenu method of the business1 object. The OrderFood method of the business1 object (inherited from the Customer class) is called, allowing the user to place an order by selecting items from the menu and specifying quantities.

More specifically, The Business class is responsible for saving the restaurant's name, the restaurant's menu, along with its prices, and the objects of the Delivery People class that represent the available delivery staff, saved inside a vector. The constructor of the class initializes these data members according to the arguments passed by the user. There are seven main public function members included. However, since the Business class inherits from the Customer Class and is declared as a friend of the Customer and Delivery Class, it also has access to the public functions of the Customer Class and the private members of the friend functions. The Business class utilizes this access to declare some of its main functions, which are further explained below:

* Getter Functions: They provide access to the private data members of the Business class by returning their respective values.

* PrintMenu: It prints the menu on the screen, displaying the index number of each item, the name of the item, and its price.

* Driver Available: This function is an example of function overloading. The first Driver Available function takes a bool value as an argument and returns another Boolean value, indicating if there are any drivers available. The second function takes an integer as an argument and outputs a vector of Delivery People class. It returns a vector of available drivers' indices.

* Order Confirmation: It checks if any drivers are available and returns a boolean value indicating whether the order is accepted.

* Assigned Driver Information: This is another example of function overloading. The first of these functions provides information about the assigned driver to the customer by returning the corresponding object from the Delivery People class. The second function returns the total distance, which is the journey from the initial position to the restaurant and finally to the customer's location, between the Delivery person and the customer's location.

* Assigned Driver to Customer: It simulates the final assignment of the selected driver to the customer by updating their availability, displaying delivery information, and showing the time that must pass before the order can be delivered.

* Pretend Delivery Function: It simulates the final delivery processes by setting the driver's position at the customer's location and changing their availability from busy to free.


The Customer class saves a vector of type string that contains the order of the customer, another vector that saves the quantity from the item that the customer desires to order, along with other variables utilized in the class functions. This class is inherited from the class ID Data, hence apart from its public functions it also has access to the ID Data functions. The Customer class member functions are explained below:

* Getter Functions: They give access to the private members by returning their respective values.

* Order Food: Allows the customer to place orders by selecting items from the menu and specifying quantities.

* Print Order: Displays the recorded orders and their quantities, referencing the restaurant's menu. This reference is achieved by passing as argument to the function a pointer to an object of class Business.

* Customer Confirmation: Confirms the order by displaying the order and allowing the customer to confirm or reject it.

* Print Id Data: This is an example of an Override function. Because ID Data class also has a function with the same name and void output to, and Customer class has access to it due to the inheritance relationship, the compiler will override one of these two functions. As the Print Id Data function from ID class is virtual, the compiler will override it and its equivalent from Customer class will be pass by default. 

After the user has entered their order, the program then checks if the restaurant can accept the order based on the availability of drivers. This check is done using the OrderConfirmation method of the business1 object. If there are available drivers and the order is confirmed, the program prompts the user for their name, x and y coordinates representing their location with respect to the restaurant. The customer's provided data (name, coordinates) is set to initialize the private members of the implicitly created ID Data class from the implicit instance of the Customer class within the business1 object. The customerConfirm method of the business1 object (inherited from the Customer class) is called, allowing the customer to confirm the order.

If the order is confirmed by the customer, an instance of the Receipt class, named receipt1, is created. The CalculateCost method of the receipt1 object is called to calculate the total cost of the customer's order and generate a receipt. The AssignDriverToCustomer method of the business1 object simulates assigning a delivery driver to the customer. A message is displayed indicating that the order will be delivered soon. The PretendDelivery method of the business1 object simulates the final delivery process.

On the other hand, if the order is not confirmed by either the restaurant or the customer, an error message is displayed in each respective case. When the customer does not confirm their order, the program gives the option of restarting the order or exiting the program. If there are no available drivers, an error message is displayed, indicating that the order cannot be placed due to all drivers being occupied, and the program exits.

The ID Data class stores the basic information of the user, which includes their name, the coordinates of the customer’s location, and a unique ID created when a customer orders from a restaurant. Similar to the class Delivery People, the ID Data class member functions include a default constructor, setter and getter functions for the private variables, and lastly, the Print Id Data function mentioned above. The latter function prints the name, unique ID, and position of the customer.

The Delivery People class stores data for each delivery worker. It includes variables such as their coordinates with respect to the restaurant, their unique ID number, and their availability. Its main public member functions consist solely of a default constructor and setter and getter functions for the private variables. As mentioned above, it designates the Business class as a friend function.

Finally, the Receipt class, as its name implies, is responsible for creating a receipt for every order generated. It only possesses one private member which corresponds to the name of the text file that is meant to be created as the receipt. The Receipt class public member function, Calculate Cost, accesses private members from the customer and business class as these two classes define the Receipt class as a friend function. The Calculate Cost function calculates the total price of the customer’s order, prints the receipt on the screen, and creates the text file representative of the receipt.

## Methods for Code Efficiency

When it comes to the methods I utilized to optimize the efficiency of the program, the most relevant ones are:

1. Inline functions: I applied the "inline" command to various member functions, including getter and setter functions, as well as specific functions like PrintMenu and GetCustomerConfirmation. This was done due to the simplicity of their definitions. Since these functions are essential and frequently called in the Main CPP file, marking them as "inline" helps optimize the program's performance.

2. Vectors: I used vectors to store data members with variable initial sizes, such as the menu, the customer's order, and the assigned delivery workers to a restaurant. Vectors optimize memory usage due to their dynamic nature. They automatically resize themselves according to the user's requirements, resulting in minimal initial memory allocation and dynamic adjustments as needed. Vectors also reduce the risk of memory leaks compared to other alternatives like dynamic arrays, as memory management is handled automatically by the program.

3. Inheritance: I employed inheritance by creating classes derived from other classes, reducing redundancy while maintaining a clear hierarchical structure in my code. The inheritance relationship, along with friendship functions, provided access to all necessary member functions in the main CPP file through a single object. Objects from other classes are created implicitly via inheritance, enhancing code organization and minimizing the use of additional tools like pointers, which could consume more memory and increase the potential for errors.

4. Multi-File Code: Organizing the code into multiple files for each class and its definitions helps optimize the program in several ways. It reduces compilation time, enhances code readability, and promotes code reusability. Compilation time is reduced because changes made to a specific file do not necessitate recompiling the entire codebase. For instance, adding an additional restaurant to the main CPP file would not require recompilation of the header and other CPP files. Each file contains a smaller piece of the code, making it easier for users to understand the code's structure, which is essential for making any necessary modifications.
