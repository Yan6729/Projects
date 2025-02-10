/*
** EPITECH PROJECT, 2024
** 102_architects.c
** File description:
** Math project
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M_PI  3.14159265358979323846

int usage(int ac, char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h') {
	printf("      x abscissa of the original point\n");
	printf("      y ordinate of the original point\n");
	printf("      transfo arg1 [arg2]\n");
	printf("      -t i j translation along vector (i, j)\n");
	printf("      -z m n scaling by factors m (x-axis) and n (y-axis)\n");
	printf("      -r d   rotation centered in O by a d degree angle\n");
	printf("      -s d   reflection over the axis passing through O with an inclination\n");
	printf("             angle of d degrees\n");
    }
}

double **translation(int ac, char **av)
{
    char *end;
    if (strtof(av[4], &end) == 0 && end == av[4] || strtof(av[5], &end) == 0 && end == av[5] || strtof(av[1], &end) == 0 && end == av[1] || strtof(av[2], &end) == 0 && end == av[2]) {
	exit(84);
    }
    if (av[3][0] == '-' && av[3][1] == 't') {
	double math[3][3];
	math[0][0] = 1;
	math[0][1] = 0;
	math[0][2] = atof(av[4]);
	math[1][0] = 0;
	math[1][1] = 1;
	math[1][2] = atof(av[5]);
	math[2][0] = 0;
	math[2][1] = 0;
	math[2][2] = 1;
	double math2[1][2];
	math2[0][0] = atof(av[1]);
	math2[0][1] = atof(av[2]);
	math2[0][2] = 1;
	double math3[1][2];
	math3[0][0] = (math2[0][0] * 1) + (math2[0][1] * 0) + (math[0][2] * 1);
	math3[0][1] = (math2[0][0] * 0) + (math2[0][1] * 1) + (math[1][2] * 1);
	math3[0][2] = 1;
	printf("Translation along vector (%.0f, %.0f)\n", math[0][2], math[1][2]);
	printf("%.2f  %.2f  %.2f\n", math[0][0], math[0][1], math[0][2]);
	printf("%.2f  %.2f  %.2f\n", math[1][0], math[1][1], math[1][2]);
	printf("%.2f  %.2f  %.2f\n", math[2][0], math[2][1], math[2][2]);
	printf("(%.2f, %.2f) => (%.2f, %.2f)\n", math2[0][0], math2[0][1], math3[0][0], math3[0][1]);
    }
}

double **reflexion(int ac, char **av)
{
    char *end;
    if (strtof(av[4], &end) == 0 && end == av[4] || strtof(av[1], &end) == 0 && end == av[1] || strtof(av[2], &end) == 0 && end == av[2]) {
	exit(84);
    }
    if (av[3][0] == '-' && av[3][1] == 's') {
	int alpha = atoi(av[4]);
	double angle = (atof(av[4]))/180 * M_PI;
        double math[3][3];
        math[0][0] = cos(2 * angle);;
        math[0][1] = sin(2 * angle);
        math[0][2] = 0;
        math[1][0] = sin(2 * angle);
        math[1][1] = -cos(2 * angle);
        math[1][2] = 0;
        math[2][0] = 0;
        math[2][1] = 0;
        math[2][2] = 1;
        double math2[1][2];
        math2[0][0] = atof(av[1]);
        math2[0][1] = atof(av[2]);
        math2[0][2] = 1;
        double math3[1][3];
        math3[0][0] = (math2[0][0] * math[0][0]) + (math2[0][1] * math[0][1]) + (0 * 0);
        math3[0][1] = (math2[0][0] * math[1][0]) + (math2[0][1] * math[1][1]) + (0 * 0);
        math3[0][2] = 1;
	printf("Reflection over an axis with an inclination angle of %d degrees\n", alpha);
        printf("%.2f  %.2f  %.2f\n", math[0][0], math[0][1], math[0][2]);
	printf("%.2f  %.2f  %.2f\n", math[1][0], math[1][1], math[1][2]);
        printf("%.2f  %.2f  %.2f\n", math[2][0], math[2][1], math[2][2]);
        printf("(%.2f, %.2f) => (%.2f, %.2f)\n", math2[0][0], math2[0][1], math3[0][0], math3[0][1]);
    }
}

double **rotation(int ac, char **av)
{
    char *end;
    if (strtof(av[4], &end) == 0 && end == av[4] || strtof(av[1], &end) == 0 && end == av[1] 
	|| strtof(av[2], &end) == 0 && end == av[2]) {
	exit(84);
    }
    if (av[3][0] == '-' && av[3][1] == 'r') {
        int alpha = atoi(av[4]);
	double angle = (atof(av[4]))/180 * M_PI;
        double math[3][3];
        math[0][0] = cos(angle);
        math[0][1] = -sin(angle);
        math[0][2] = 0;
        math[1][0] = sin(angle);
        math[1][1] = cos(angle);
        math[1][2] = 0;
        math[2][0] = 0;
        math[2][1] = 0;
        math[2][2] = 1;
        double math2[1][2];
        math2[0][0] = atof(av[1]);
        math2[0][1] = atof(av[2]);
        math2[0][2] = 1;
        double math3[1][3];
        math3[0][0] = (math2[0][0] * math[0][0]) + (math2[0][1] * math[0][1]) + (math[0][2] * 0);
        math3[0][1] = (math2[0][0] * math[1][0]) + (math2[0][1] * math[1][1]) + (math[1][2] * 0);
        math3[0][2] = 1;
	printf("Rotation by a %d degree angle\n", alpha);
        printf("%.2f  %.2f  %.2f\n", math[0][0], math[0][1], math[0][2]);
        printf("%.2f  %.2f  %.2f\n", math[1][0], math[1][1], math[1][2]);
        printf("%.2f  %.2f  %.2f\n", math[2][0], math[2][1], math[2][2]);
        printf("(%.2f, %.2f) => (%.2f, %.2f)\n", math2[0][0], math2[0][1], math3[0][0], math3[0][1]);
    }
}

double **scalaire(int ac, char **av)
{
       char *end;
    if (strtof(av[4], &end) == 0 && end == av[4] || strtof(av[5], &end) == 0 && end == av[5]
|| strtof(av[1], &end) == 0 && end == av[1] || strtof(av[2], &end) == 0 && end == av[2]) {
	exit(84);
    }
    if (av[3][0] == '-' && av[3][1] == 'z') {
        double math[3][3];
        math[0][0] = atof(av[4]);
        math[0][1] = 0;
        math[0][2] = 0;
        math[1][0] = 0;
        math[1][1] = atof(av[5]);
        math[1][2] = 0;
        math[2][0] = 0;
        math[2][1] = 0;
        math[2][2] = 1;
        double math2[1][2];
        math2[0][0] = atof(av[1]);
        math2[0][1] = atof(av[2]);
        math2[0][2] = 1;
        double math3[1][3];
        math3[0][0] = (math2[0][0] * math[0][0]) + (math2[0][1] * 0) + (1 * 0);
        math3[0][1] = (math2[0][0] * 0) + (math2[0][1] * math[1][1]) + (0 * 1);
        math3[0][2] = 1;
        printf("Scaling by factors %.0f and %.0f\n", math[0][0], math[1][1]);
        printf("%.2f  %.2f  %.2f\n", math[0][0], math[0][1], math[0][2]);
        printf("%.2f  %.2f  %.2f\n", math[1][0], math[1][1], math[1][2]);
        printf("%.2f  %.2f  %.2f\n", math[2][0], math[2][1], math[2][2]);
        printf("(%.2f, %.2f) => (%.2f, %.2f)\n", math2[0][0], math2[0][1], math3[0][0], math3[0][1]);
    }
}

double **combinaison(int ac, char **av) {
    if (av[3][0] == '-' && av[3][1] == 't' && av[6][0] == '-' && av[6][1] == 'z' && av[9][0] == '-' && av[9][1] == 'r' && av[11][0] == '-' && av[11][1] == 's') {
	double trans[3][3];
	trans[0][0] = 1;
        trans[0][1] = 0;
        trans[0][2] = atof(av[4]);
        trans[1][0] = 0;
        trans[1][1] = 1;
        trans[1][2] = atof(av[5]);
        trans[2][0] = 0;
        trans[2][1] = 0;
        trans[2][2] = 1;

        double trans2[1][2];
        trans2[0][0] = atof(av[1]);
        trans2[0][1] = atof(av[2]);
        trans2[0][2] = 1;

        double trans3[1][2];
        trans3[0][0] = (trans2[0][0] * 1) + (trans2[0][1] * 0) + (trans[0][2] * 1);
        trans3[0][1] = (trans2[0][0] * 0) + (trans2[0][1] * 1) + (trans[1][2] * 1);
        trans3[0][2] = 1;

	double scal[3][3];
	scal[0][0] = atof(av[7]);
	scal[0][1] = 0;
	scal[0][2] = 0;
	scal[1][0] = 0;
	scal[1][1] = atof(av[8]);
	scal[1][2] = 0;
	scal[2][0] = 0;
	scal[2][1] = 0;
	scal[2][2] = 1;

	double scal2[1][2];
	scal2[0][0] = trans3[0][0];
	scal2[0][1] = trans3[0][1];
	scal2[0][2] = 1;

	double scal3[1][3];
	scal3[0][0] = (scal2[0][0] * scal[0][0]) + (scal2[0][1] * 0) + (1 * 0);
	scal3[0][1] = (scal2[0][0] * 0) + (scal2[0][1] * scal[1][1]) + (0 * 1);
	scal3[0][2] = 1;

	int alpha1 = atoi(av[10]);
	double angle1 = (atof(av[4]))/180 * M_PI;
	double rotat[3][3];
	rotat[0][0] = cos(angle1);
	rotat[0][1] = -sin(angle1);
	rotat[0][2] = 0;
	rotat[1][0] = sin(angle1);
	rotat[1][1] = cos(angle1);
	rotat[1][2] = 0;
	rotat[2][0] = 0;
	rotat[2][1] = 0;
	rotat[2][2] = 1;

	double rotat2[1][2];
	rotat2[0][0] = scal3[0][0];
	rotat2[0][1] = scal3[0][1];
	rotat2[0][2] = 1;

	double rotat3[1][3];
	rotat3[0][0] = (rotat2[0][0] * rotat[0][0]) + (rotat2[0][1] * rotat[0][1]) + (rotat[0][2] * 0);
	rotat3[0][1] = (rotat2[0][0] * rotat[1][0]) + (rotat2[0][1] * rotat[1][1]) + (rotat[1][2] * 0);
	rotat3[0][2] = 1;

	int alpha2 = atoi(av[12]);
	double angle2 = (atof(av[12]))/180 * M_PI;
	double reflex[3][3];
	reflex[0][0] = cos(2 * angle2);;
	reflex[0][1] = sin(2 * angle2);
	reflex[0][2] = 0;
	reflex[1][0] = sin(2 * angle2);
	reflex[1][1] = -cos(2 * angle2);
	reflex[1][2] = 0;
	reflex[2][0] = 0;
	reflex[2][1] = 0;
	reflex[2][2] = 1;

	double reflex2[1][2];
	reflex2[0][0] = rotat3[0][0];
	reflex2[0][1] = rotat3[0][1];
	reflex2[0][2] = 1;

	double reflex3[1][3];
	reflex3[0][0] = (reflex2[0][0] * reflex[0][0]) + (reflex2[0][1] * reflex[0][1]) + (0 * 0);
	reflex3[0][1] = (reflex2[0][0] * reflex[1][0]) + (reflex2[0][1] * reflex[1][1]) + (0 * 0);
	reflex3[0][2] = 1;

	printf("ranslation along vector (%.0f, %.0f)\n", trans[0][2], trans[1][2]);
	printf("Scaling by factors %.0f and %.0f\n", scal[0][0], scal[1][1]);
	printf("Rotation by a %d degree angle\n", alpha1);
	printf("Reflection over an axis with an inclination angle of %d degrees\n", alpha2);
	printf("%.2f  %.2f  %.2f\n", reflex[0][0], reflex[0][1], reflex[0][2]);
	printf("%.2f  %.2f  %.2f\n", reflex[1][0], reflex[1][1], reflex[1][2]);
	printf("%.2f  %.2f  %.2f\n", reflex[2][0], reflex[2][1], reflex[2][2]);
	printf("(%.2f, %.2f) => (%.2f, %.2f)\n", trans2[0][0], trans2[0][1], reflex3[0][0], reflex3[0][1]);
    }
}

int main(int ac, char **av)
{
    if (ac == 1) {
	exit(84);
    }
    if (ac == 2) {
	usage(ac, av);
    } else if (ac == 6) {
	translation(ac, av);
	scalaire(ac, av);
    } else if (ac == 5) {
	reflexion(ac, av);
	rotation(ac, av);
    } else if (ac == 13) {
	combinaison(ac, av);
    } else {
	exit(84);
    }
}
