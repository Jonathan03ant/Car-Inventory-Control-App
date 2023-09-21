# Car-Inventory-Control-App
This repository contains a simple Car Inventory Tracker application written in C. The application allows users to manage and track information about various cars, including their General Information, Mechanical details, and Status. This was an early self-study project for my first Systems Programming (COMP2401-Introduction to Systems Programing in C) class on Summer 2023.

## Features
**A dding Cars:** Add new cars to the inventory with their general details, mechanical information, and status.

**Viewing Inventory:** Display the entire inventory or filter it based on specific criteria such as brand name, model, or color.

**Memory Management:** Efficient memory handling is implemented to ensure optimized performance and prevent memory leaks.

**File Integration:** Integration with CSV files for easy import and export of car inventory data.

## Implementation Details
**Data Structures**
**Linked List:** Car data is stored using a linked list to allow for efficient addition, removal, and traversal of the inventory.

**Dynamic Arrays:** Certain aspects of car data, such as our Main Car Storage which is the backbone of all Data structures in the application, and Rental Customers, are stored using dynamic arrays to accommodate varying data sizes.

## Memory Management
**Dynamic Memory Allocation:** The program utilizes dynamic memory allocation (malloc, calloc, realloc, free) to manage memory efficiently, ensuring proper deallocation to prevent memory leaks.
## File Handling
**CSV Integration:** Car inventory data can be imported from and exported to CSV files, allowing for easy integration with external data sources.
## Storage
**Storage Management:** The program employs a storage mechanism to organize and maintain multiple inventories, enabling the management of different car collections. Inventories are tracked by Dynamic Array.

**Efficient Data Retrieval:** Techniques like indexing and hashing are utilized to quickly retrieve and display specific car information.