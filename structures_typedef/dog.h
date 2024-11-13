#ifndef DOG_H
#define DOG_H

/*
 * File: dog.h
 * Description: Header file that contains prototypes functions and structures
 * This header ensures that the functions and structures
 * can be used in other files by declaring it here, so other source files
 * can include this header and call it.
 */

/**
 * struct dog - About dog informations
 * @name: doggo name
 * @age: doggo age
 * @owner: doggo owner
 *
 * Description: struct. about doggo
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/**
 * init_dog - initialize a variable of type struct dog
 * Description :  initialize a variable of type struct dog
 * @d: structure
 * @name: doggo name
 * @age: doggo age
 * @owner: doggo owner
 * Return:	/
 */
void init_dog(struct dog *d, char *name, float age, char *owner);

/**
 * print_dog - initialize a variable of type struct dog
 * Description :  initialize a variable of type struct dog
 * @d: structure dog
 * Return:	/
 */
void print_dog(struct dog *d);




#endif