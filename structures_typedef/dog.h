#ifndef DOG_H
#define DOG_H

/**
 * struct dog - define a dog type
 * @name: Dog's name
 * @age: Dog's age
 * @owner: Dog's owner
 *
 * Description: a custom defined structure of a dog
 */

typedef struct dog
{
	char *name;
	float age;
	char *owner;
} dog;

#endif
