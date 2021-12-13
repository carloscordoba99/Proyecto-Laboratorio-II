#ifndef ARTICULO_MOD_H_INCLUDED
#define ARTICULO_MOD_H_INCLUDED
void Modificasion_art()
{

    int opc;
    while(true)
    {
        system("cls");
        cout<<"Modificaci�n de art�culos"<<endl;
        cout<<"1. Nombre"<<endl;
        cout<<"2. Precio"<<endl;
        cout<<"3. Stock"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Ingrese la opci�n: "<<endl;
        cin>>opc;
        switch(opc)
        {
        case 1:
            art_nombre();
            system("pause");
            break;
        case 2:
            art_precio();
            system("pause");
            break;
        case 3:
            art_stok();
            system("pause");
            break;
        case 0:
            return ;
        default:
            cout<<"Opci�n incorrecta. Presione una tecla para continuar.";
            system("pause>null");
            break;
        }
    }

};

void art_nombre()
{
    system("cls");
    int nro;
    char nombre[20];
    Articulo reg;
    cout<<"Indique el nro de art�culo a cambiar."<<endl;
    cin>>nro;
    int pos=buscar_art(nro);
    if(pos==-1)
    {
        cout<<"No se encontr� en los archivos."<<endl;
        return;
    }
    if(reg.Leer_de_disco(pos)==true)
    {
        cout<<"Ingrese el nuevo nombre."<<endl;
        cargarCadena(nombre,19);
        reg.set_nombre(nombre);

            if(reg.Modificar_de_disco(pos)==true)
            {
                cout<<"Se modific�."<<endl;
            }

    }

};

void art_precio()
{
    system("cls");
    int nro;
    float precio;
    Articulo reg;
    cout<<"Indique el nro. de art�culo a cambiar."<<endl;
    cin>>nro;
    int pos=buscar_art(nro);
    if(pos==-1)
    {
        cout<<"No se encontr� en los arch�vos."<<endl;
        return;
    }
    if(reg.Leer_de_disco(pos)==true)
    {
        cout<<"Ingrese el nuevo precio."<<endl;
        cin>>precio;
        reg.set_precio(precio);
            if(reg.Modificar_de_disco(pos)==true)
            {
                cout<<"Se modific�."<<endl;
            }
    }

};

void art_stok()
{
    system("cls");
    int nro,stok;
    Articulo reg;
    cout<<"Indique el nro de art�culo a cambiar."<<endl;
    cin>>nro;
    int pos=buscar_art(nro);
    if(pos==-1)
    {
        cout<<"No se encontr� en los archivos."<<endl;
        return;
    }
    if(reg.Leer_de_disco(pos)==true)
    {
        cout<<"Ingrese el nuevo stock."<<endl;
        cin>>stok;
        reg.set_stock(stok);
            if(reg.Modificar_de_disco(pos)==true)
            {
                cout<<"Se modific�."<<endl;
            }

    }

};


#endif // ARTICULO_MOD_H_INCLUDED
