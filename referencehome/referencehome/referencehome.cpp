#include <iostream>
using namespace std;
int* create(int& l) {
	int* poin = new int[l];
	return poin;
}
void random(int& l, int*& refpoin) {
	srand(time(NULL));
	int min, max;
	min = -10;
	max = 10;
	for (int i = 0; i < l; i++)
	{
		refpoin[i] = min + rand() % (max - min + 1);
	}

}
void random2(int& l, int*& refpoin) {
	srand(time(NULL));
	int min, max;
	min = -100;
	max = 100;
	for (int i = 0; i < l; i++)
	{
		refpoin[i] = (min + rand() % (max - min + 1)) / 10;
	}

}
void random3(int& l, int*& refpoin) {
	srand(time(NULL));
	int min, max;
	min = 0;
	max = 100;
	for (int i = 0; i < l; i++)
	{
		refpoin[i] = (min + rand() % (max - min + 1)) ;
	}

}
void show(int& l, int*& refpoin) {
	cout << endl;
	for (int i = 0; i < l; i++)
	{
		cout << refpoin[i] << " ";
	}
	cout << endl;
}
int*& onlypositivesandzero(int& l, int*& refpoin) {
	int y = 0;
	for (int i = 0; i < l; i++)
	{
		if (refpoin[i] >= 0)
		{
			y++;
		}


	}
	int* temp = new int[y];
	int*& temp_ref = temp;
	y = 0;
	for (int i = 0; i < l; i++)
	{
		if (refpoin[i] < 0)
		{
			continue;
		}
		temp_ref[y] = refpoin[i];
		y++;
	}
	l = y;
	return temp_ref;

}
int*& intersection(int& l, int*& refpoin, int& l2, int*& refpoin2) {
	int r = 0;
	for (int i = 0; i < l; i++)
	{
		for (int j = i; j < l2; j++)
		{
			if (refpoin[i] == refpoin2[j])
			{
				r++;
				break;
			}

		}


	}
	int* temp = new int[r];
	int*& temp_ref = temp;
	r = 0;
	for (int i = 0; i < l; i++)
	{
		for (int j = i; j < l2; j++)
		{
			if (refpoin[i] == refpoin2[j])
			{
				temp_ref[r] = refpoin[i];
				r++;
				break;
			}

		}


	}
	l = r;
	return temp_ref;

}

int*& substraction(int& l, int*& refpoin, int& l2, int*& refpoin2) {
	int r = l;
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < l2; j++)
		{
			if (refpoin[i] == refpoin2[j])
			{
				r--;
				break;
			}

		}


	}
	int* temp = new int[r];
	int*& temp_ref = temp;
	r = 0;
	bool b = true;
	for (int i = 0; i < l; i++)
	{
		b = true;
		for (int j = 0; j < l2; j++)
		{
			if (refpoin[i] == refpoin2[j])
			{
				b = false;

				break;
			}

		}
		if (b == true) {
			temp_ref[r] = refpoin[i];
			r++;
		}


	}
	l = r;
	return temp_ref;

}


int*& conenction(int& l, int*& refpoin, int& l2, int*& refpoin2) {
	int r = l + l2;
	int* temp = new int[r];
	int*& temp_ref = temp;
	for (int i = 0; i < l; i++)
	{
		temp_ref[i] = refpoin[i];
	}
	for (int i = 0; i < l2; i++)
	{
		temp_ref[i + l] = refpoin2[i];
	}
	l = r;
	return temp_ref;

}
int*& onlyinone(int& l, int*& refpoin, int& l2, int*& refpoin2) {
	int r = l;
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < l2; j++)
		{
			if (refpoin[i] == refpoin2[j])
			{
				r--;
				break;
			}

		}


	}
	int r2 = l2;
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < l2; j++)
		{
			if (refpoin[i] == refpoin2[j])
			{
				r2--;
				break;
			}

		}


	}
	int* temp = new int[r + r2];
	int*& temp_ref = temp;
	r = 0;
	bool b = true;
	for (int i = 0; i < l; i++)
	{
		b = true;
		for (int j = 0; j < l2; j++)
		{
			if (refpoin[i] == refpoin2[j])
			{
				b = false;

				break;
			}

		}
		if (b == true) {
			temp_ref[r] = refpoin[i];
			r++;
		}


	}

	r2 = 0;
	b = true;
	for (int i = 0; i < l; i++)
	{
		b = true;
		for (int j = 0; j < l2; j++)
		{
			if (refpoin[i] == refpoin2[j])
			{
				b = false;

				break;
			}

		}
		if (b == true) {
			temp_ref[r2 + r] = refpoin2[i];
			r2++;
		}


	}

	l = r + r2;
	return temp_ref;

}
int*& onlycomposite(int& l, int*& refpoin) {
	int r = 0;


	for (int i = 0; i < l; i++)
	{
		bool b = true;
		for (int j = 2; j < refpoin[i]; j++)
		{
			if (refpoin[i] % j == 0)
			{
				b = false;
				break;
			}

		}
		if (b = false)
		{
			r++;
		}
	}
	int* temp = new int[r];
	int*& temp_ref = temp;
	r = 0;
	for (int i = 0; i < l; i++)
	{
		bool b = true;
		for (int j = 2; j < refpoin[i]; j++)
		{
			if (refpoin[i] % j == 0)
			{
				b = false;
				break;
			}

		}
		if (b == false)
		{
			temp_ref[r] = refpoin[i];
			r++;
		}
	}
	l = r;
	return temp_ref;

}
int main()
{
	int l;
	cin >> l;
	int& l_reference = l;
	int* arrref = create(l_reference);
	int*& arrefpoin = arrref;
	random(l_reference, arrefpoin);
	show(l_reference, arrefpoin);
	arrefpoin = onlypositivesandzero(l_reference, arrefpoin);
	show(l_reference, arrefpoin);



	cin >> l_reference;
	int* a = create(l_reference);
	int*& a_rp = a;
	random(l_reference, a);
	show(l_reference, a_rp);
	int* b = create(l_reference);
	int*& b_rp = b;
	random2(l_reference, b);
	show(l_reference, b_rp);
	a_rp = conenction(l_reference, a_rp, l_reference, b_rp);
	show(l_reference, a_rp);


	cin >> l_reference;
	int* a2 = create(l_reference);
	int*& a2_rp = a2;
	random(l_reference, a2);
	show(l_reference, a2_rp);
	int* b2 = create(l_reference);
	int*& b2_rp = b2;
	random2(l_reference, b2);
	show(l_reference, b2_rp);
	a2_rp = intersection(l_reference, a2_rp, l_reference, b2_rp);
	show(l_reference, a2_rp);




	cin >> l_reference;
	int* a3 = create(l_reference);
	int*& a3_rp = a3;
	random(l_reference, a3);
	show(l_reference, a3_rp);
	int* b3 = create(l_reference);
	int*& b3_rp = b3;
	random2(l_reference, b3);
	show(l_reference, b3_rp);
	a3_rp = substraction(l_reference, a3_rp, l_reference, b3_rp);
	show(l_reference, a3_rp);





	cin >> l_reference;
	int* a4 = create(l_reference);
	int*& a4_rp = a4;
	random(l_reference, a4);
	show(l_reference, a4_rp);
	int* b4 = create(l_reference);
	int*& b4_rp = b4;
	random2(l_reference, b4);
	show(l_reference, b4_rp);
	a4_rp = onlyinone(l_reference, a4_rp, l_reference, b4_rp);

	show(l_reference, a4_rp);



	cin >> l_reference;
	int* a2rrref = create(l_reference);
	int*& a2rrefpoin = a2rrref;
	random3(l_reference, a2rrefpoin);
	show(l_reference, a2rrefpoin);
	a2rrefpoin = onlycomposite(l_reference, a2rrefpoin);
	show(l_reference, a2rrefpoin);

}


