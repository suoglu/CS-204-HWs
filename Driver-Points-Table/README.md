# Driver Points Table with Linked List
Simple program that takes driver names and points, stores them alphabetically in a link list.  

## How to use:
1. Follow on screen instructions
2. Add drivers:
 * By console (op 2)
 * By File (op 1)
3. Continue step 2 until all drivers were entered
4. Display drivers (op 3)
5. Exit and delete link list (op 4)

## Warnings 
* Program does not apply input check for driver points, thus if non integer input given to  driver points program will crash
* Input file must be in following format: 
 * name0 point0 name1 point1 ...
 * any number of space/s or line brake can be used between names and points
 * each name must be followed by point, otherwise program will stop responding
* A poor input check used for operation code input. Thus incase of a string input, program gives an error for each char
