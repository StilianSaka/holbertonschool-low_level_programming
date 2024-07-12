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
} dog_t;

void init_dog(dog_t *d, char *name, float age, char *owner);
void print_dog(dog_t *d);
dog_t  *new_dog(char *name, float age, char *owner);

#endif
