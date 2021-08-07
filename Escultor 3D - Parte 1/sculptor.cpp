#include "sculptor.h"
#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    nx = _nx;
    ny = _ny;
    nz = _nz;

    v = new Voxel**[nx];
    v[0] = new Voxel*[nx*ny];
    v[0][0] = new Voxel[nx*ny*nz];

    for (int i = 1; i < nx; i++)
    {
        v[i] = v[i-1] + ny;
    }
    for (int i = 1; i < nx*ny; i++)
    {
        v[0][i] = v[0][i-1] + nz;
    }   
}
Sculptor::~Sculptor()
{
    delete v[0][0];
    delete v[0];
    delete v;
}
void Sculptor::setColor(float r, float g, float b, float alpha)
{
    if(r >=0 && r<=1)
    {
        this -> r = r;
    }
    if(g >=0 && g<=1)
    {
        this -> g = g;
    }
    if(b >=0 && b<=1)
    {
        this -> b = b;
    }
    if(a >=0 && a<=1)
     {
        a = alpha;
    }
}
void Sculptor::putVoxel(int x, int y, int z)
{
    v[x][y][z].isOn = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
}
void Sculptor::cutVoxel(int x, int y, int z)
{
    v[x][y][z].isOn = false;
}
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for (int x = x0; x < x1; x++)
    {
        for (int y = y0; y < y1; y++)
        {
            for (int z = z0; z < z1; z++)
            {
                putVoxel(x,y,z);
            } 
        }
    }
}
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for (int x = x0; x < x1; x++)
    {
        for (int y = y1; y < y1; y++)
        {
            for (int z = z0; z < z1; z++)
            {
                cutVoxel(x,y,z);
            } 
        }
    }
}
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    float eq;
    for (int x = 0; x < nx; x++)
    {
        for (int y = 0; y < ny; y++)
        {
            for (int z = 0; z < nz; z++)
            {
                eq = pow(x-xcenter,2) + pow(y-ycenter,2) + pow(z-zcenter,2);
                if(eq < pow(radius,2))
                {
                    putVoxel(x,y,z);
                }
            } 
        }
    }
}
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    float eq;
    for (int x = 0; x < nx; x++)
    {
        for (int y = 0; y < ny; y++)
        {
            for (int z = 0; z < nz; z++)
            {
                eq = pow(x-xcenter,2) + pow(y-ycenter,2) + pow(z-zcenter,2);
                if(eq < pow(radius,2))
                {
                    cutVoxel(x,y,z);
                }
            } 
        }
    }
}
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    float eq;
    for (int x = 0; x < nx; x++)
    {
        for (int y = 0; y < ny; y++)
        {
            for (int z = 0; z < nz; z++)
            {
                eq = pow(x-xcenter,2)/pow(rx,2) + pow(y-ycenter,2)/pow(ry,2) + pow(z-zcenter,2)/pow(rz,2);
                if(eq < 1)
                {
                    putVoxel(x,y,z);
                }
            } 
        }
    }
}
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    float eq;
    for (int x = 0; x < nx; x++)
    {
        for (int y = 0; y < ny; y++)
        {
            for (int z = 0; z < nz; z++)
            {
                eq = pow(x-xcenter,2)/pow(rx,2) + pow(y-ycenter,2)/pow(ry,2) + pow(z-zcenter,2)/pow(rz,2);
                if(eq < 1)
                {
                    cutVoxel(x,y,z);
                }
            } 
        }
    }
}
void Sculptor::writeOFF(const char* filename)
{
    ofstream arq;
    fixed(arq);
    arq.open(filename);

    int contador = 0;
    int pos = 0;

    if(arq.is_open())
    {
        cout << "Arquivo aberto!" << endl;

        arq << "OFF" << endl;

        for (int x = 0; x < nx; x++)
        {
            for (int y = 0; y < ny; y++)
            {
                for (int z = 0; z < ny; z++)
                {
                    if(v[x][y][z].isOn)
                    {
                        contador++;
                    }
                } 
            }
        }

        arq << contador*8 << " " << contador*6 << " " << 0 << endl;

        for (int x = 0; x < nx; x++)
        {
            for (int y = 0; y < ny; y++)
            {
                for (int z = 0; z < ny; z++)
                {
                    if(v[x][y][z].isOn)
                    {
                       arq << x-0.5 << " " << y+0.5 << " " << z-0.5 << endl;
                       arq << x-0.5 << " " << y-0.5 << " " << z-0.5 << endl;
                       arq << x+0.5 << " " << y-0.5 << " " << z-0.5 << endl;
                       arq << x+0.5 << " " << y+0.5 << " " << z-0.5 << endl;
                       arq << x-0.5 << " " << y+0.5 << " " << z+0.5 << endl;
                       arq << x-0.5 << " " << y-0.5 << " " << z+0.5 << endl;
                       arq << x+0.5 << " " << y-0.5 << " " << z+0.5 << endl;
                       arq << x+0.5 << " " << y+0.5 << " " << z+0.5 << endl;
                    }
                } 
            }
        }

        for (int x = 0; x < nx; x++)
        {
            for (int y = 0; y < ny; y++)
            {
                for (int z = 0; z < ny; z++)
                {
                    if(v[x][y][z].isOn)
                    {
                        arq << 4 << " " << pos+0 << " " << pos+3 << " " << pos+2 << " " << pos+1 << " " << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << endl;

                        arq << 4 << " " << pos+4 << " " << pos+5 << " " << pos+6 << " " << pos+7 << " " << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << endl;

                        arq << 4 << " " << pos+0 << " " << pos+1 << " " << pos+5 << " " << pos+4 << " " << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << endl;

                        arq << 4 << " " << pos+0 << " " << pos+4 << " " << pos+7 << " " << pos+3 << " " << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << endl;

                        arq << 4 << " " << pos+3 << " " << pos+7 << " " << pos+6 << " " << pos+2 << " " << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << endl;

                        arq << 4 << " " << pos+1 << " " << pos+2 << " " << pos+6 << " " << pos+5 << " " << v[x][y][z].r << " " << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << endl;

                        pos += 8;
                    }
                } 
            }
        }

        arq.close();
        cout << "Arquivo criado!" << endl;
    }
    else
    {
        cout << "Falha no arquivo" << endl;
    }
}