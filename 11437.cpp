#include<stdio.h>
#include<math.h>


double Ax, Ay, Bx, By, Cx, Cy;
double Dx, Dy, Ex, Ey, Fx, Fy;
double Px, Py, Qx, Qy, Rx, Ry;
double A1, A2, B1, B2, C1, C2;
double PQ, QR, RP;
double AREA, S;


int main(){
	freopen("11437.txt", "r", stdin);
	int t;
	double det;
	scanf("%d", &t);
	while(t--){
		scanf("%lf%lf%lf%lf%lf%lf", &Ax, &Ay, &Bx, &By, &Cx, &Cy);
		
		Ex = (2*Cx+Ax)/3.0; Ey = (2*Cy+Ay)/3.0;
		Dx = (2*Bx+Cx)/3.0; Dy = (2*By+Cy)/3.0;
		Fx = (2*Ax+Bx)/3.0; Fy = (2*Ay+By)/3.0;

		A1 = Ey-By; B1 = Bx-Ex; C1 = A1*Bx+B1*By;
		A2 = Dy-Ay; B2 = Ax-Dx; C2 = A2*Ax+B2*Ay;
		det = A1*B2 - A2*B1;
		Px = (B2*C1 - B1*C2)/det; Py = (A1*C2 - A2*C1)/det;

		A1 = Fy-Cy; B1 = Cx-Fx; C1 = A1*Cx+B1*Cy;
		A2 = Ey-By; B2 = Bx-Ex; C2 = A2*Bx+B2*By;
		det = A1*B2 - A2*B1;
		Qx = (B2*C1 - B1*C2)/det; Qy = (A1*C2 - A2*C1)/det;

		A1 = Fy-Cy; B1 = Cx-Fx; C1 = A1*Cx+B1*Cy;
		A2 = Dy-Ay; B2 = Ax-Dx; C2 = A2*Ax+B2*Ay;
		det = A1*B2 - A2*B1;
		Rx = (B2*C1 - B1*C2)/det; Ry = (A1*C2 - A2*C1)/det;

		PQ = sqrt(((Px-Qx)*(Px-Qx)) + ((Py-Qy)*(Py-Qy)));
		QR = sqrt(((Qx-Rx)*(Qx-Rx)) + ((Qy-Ry)*(Qy-Ry)));
		RP = sqrt(((Rx-Px)*(Rx-Px)) + ((Ry-Py)*(Ry-Py)));

		S = (PQ+QR+RP)/2.0;

		AREA = sqrt(S*(S-PQ)*(S-QR)*(S-RP));
		printf("%.0lf\n", AREA);
	}
	return 0;
}