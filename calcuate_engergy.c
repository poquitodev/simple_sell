#include <stdio.h>

int main()
{
	double u_tension, i_intensity, t_time, r_puissance;

	printf("sisair la valeur de la tension: ");
	scanf("%lf", &u_tension);
	printf("sisair la valeur de l'intensite: ");
	scanf("%lf", &i_intensity);

	printf("on utilise la relation de P = U * I pour calculer la puissance:\n");
	r_puissance = u_tension * i_intensity;
	printf("P = %.2fw\n", r_puissance);
	printf("sisair la valeur du temps: ");
	scanf("%lf", &t_time);
	printf("on utilise la relation de E = P * T pour calculer l'energie:\n");
	printf("E = %.2fj\n", r_puissance * t_time);
	return (0);
}
