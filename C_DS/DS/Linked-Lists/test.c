#define PRINT(int) printf("int = %d",int)
main()
{
	int x,y,z; x = 03; y = 02; z =01;
	PRINT(x^x);
	z <<= 3; // z = z << 3;
	PRINT(x);
	y >>= 3; PRINT(y);
}


