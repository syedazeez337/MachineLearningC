

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float train[][2] = {
	{0,0},
	{1,2},
	{2,4},
	{3,6},
	{4,8},
};  //parameters

#define train_count (sizeof(train)/sizeof(train[0]))

// y = x * w;
float rand_float(void)
{
	return (float) rand() / (float) RAND_MAX;
}

float cost(float w)
{
	float result = 0.0f;
	size_t n = train_count;
	for(size_t i = 0; i < n; ++i)
	{
		float x = train[i][0];
		float y = x * w;
		float d = y - train[i][1];
		result += d*d;
	}
	result /= n;
	return result;
}

float dcost(float w)
{
	float result = 0.0f;
	size_t n = train_count;
	for(size_t i = 0; i < n; ++i)
	{
		float x = train[i][0];
		float y = train[i][1];
		result += 2 * (x*w - y) * x;
	}
	result /= n;
	return 0;
}

int main(void)
{
	//srand(time(0));
	srand(69);
	float w = rand_float() * 10.0f;

	float eps = 1e-3;
	float rate = 1e-3;

	for(size_t i = 0;i < 100; ++i)
	{
		float dcost = (cost(w - eps) - cost(w))/eps;
	        printf("%f\n", cost(w));
	        w -= rate*dcost;
	        printf("%f\n", cost(w));
	}
	printf("X--------------X\n");

	printf("%f", dcost(w));

	return 0;
}
/*
        printf("%f\n", cost(w - eps));
	printf("%f\n", cost(w - eps*2));
	printf("%f\n", dcost);
*/
