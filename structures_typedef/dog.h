#ifndef _DOG_H_
#define _DOG_H_

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
 * init_dog - initialize dog structure
 * Description : initialize dog structure
 * @d: pointer to the structure dog
 * @name: doggo name
 * @age: doggo age
 * @owner: doggo owner
 *
 * Return:	/
 */
void init_dog(struct dog *d, char *name, float age, char *owner);

#endif /* _DOG_H_ */
