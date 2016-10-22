#include	<stdio.h>
#include	<string.h>
#include	<osaka.h>

main(argc, argv)
int argc;
char  **argv; 
{
	int i,j,k,l,m, n;
	unsigned long inmoji2, henmoji2;
	char inbuf[8192], outbuf[8400];
	char inmoji, henmoji;

	while(gets(inbuf) != NULL)
	{
		inmoji = inbuf[0];
		inmoji2 = (unsigned long)inmoji & 0x0ff;
		if (inmoji2 > 0x0A0)
			inmoji2 = (inmoji2 << 8) | ((unsigned long)inbuf[1] & 0x0ff);
		i = 0;
		k = 0;
		while(1)
		{
			if (inmoji2 == 0)
			{
				outbuf[k] = inmoji;
				printf("%s\n", outbuf);
				break;
			}
			henmoji = henkan[0].indata[0];
			henmoji2 = (unsigned long)henmoji & 0x0ff;
			if (henmoji2 > 0x0A0)
				henmoji2 = (henmoji2 << 8) |
					 ((unsigned long)henkan[0].indata[1] & 0x0ff);
			j = 0;
			l = 0;
			m = 5000;
			n = 5000;
			while(1)
			{
				for (; henmoji2 < inmoji2 && m != 0; j++, m--)
				{
					if (henmoji2 == 0) break;
					henmoji = henkan[j+1].indata[l];
					henmoji2 = (unsigned long)henmoji & 0x0ff;
					if (henmoji2 > 0x0A0)
						henmoji2 = (henmoji2 << 8) |
					 		((unsigned long)henkan[j+1].indata[l+1] & 0x0ff);
				}
				if (henmoji2 == 0 || inmoji2 < henmoji2 || m == 0)
				{
					outbuf[k] = inbuf[i];
					inmoji2 = (unsigned long)inbuf[i] & 0x0ff;
					k++;
					i++;
					if (inmoji2 > 0x0A0)
					{
						outbuf[k] = inbuf[i];
						k++;
						i++;
					}
					inmoji = inbuf[i];
					inmoji2 = (unsigned long)inmoji & 0x0ff;
					if (inmoji2 > 0x0A0)
						inmoji2 = (inmoji2 << 8) |
							 ((unsigned long)inbuf[i+1] & 0x0ff);
					break;
				}
				for (m = 0; inmoji2 == henmoji2 && j+m < n; m++)
				{
					henmoji2 = (unsigned long)henkan[j+m+1].indata[l] & 0x0ff;
					if (inmoji2 > 0x0A0)
					{
						henmoji2 = (henmoji2 << 8)|
							(unsigned long)henkan[j+m+1].indata[l+1] & 0x0ff;
					}
				}

				n = j+m;
				l++;
				if (inmoji2 > 0x0A0) l++;

				inmoji = inbuf[i+l];
				inmoji2 = (unsigned long)inmoji & 0x0ff;
				if (inmoji2 > 0x0A0)
					inmoji2 = (inmoji2 << 8) |
						 ((unsigned long)inbuf[i+l+1] & 0x0ff);
				henmoji = henkan[j].indata[l];
				henmoji2 = (unsigned long)henmoji & 0x0ff;
				if (henmoji2 > 0x0A0)
					henmoji2 = (henmoji2 << 8) |
				 		((unsigned long)henkan[j].indata[l+1] & 0x0ff);
				if ( henmoji2 == 0 )
				{
					for (; m > 0; m--)
					{
						n = strlen(&henkan[j+m-1].indata[0]);
						if (strncmp(&inbuf[i], &henkan[j+m-1].indata[0], n) == 0)break;
					}
					j += m-1;
					i += n;
					inmoji = inbuf[i];
					for (l = 0; henkan[j].outdata[l] != 0; l++,k++)
						outbuf[k] = henkan[j].outdata[l];
					break;
				}
				if ( inmoji2 == 0 )
				{
					while( l != 0 )
					{
						l--;
						outbuf[k] = inbuf[i];
						k++;
						i++;
					}
					break;
				}
			}
		}
	}
}
