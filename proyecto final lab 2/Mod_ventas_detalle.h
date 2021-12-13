#ifndef MOD_VENTAS_DETALLE_H_INCLUDED
#define MOD_VENTAS_DETALLE_H_INCLUDED

/*
void Mod_ventas_detalles()
{
    int opc;
    while(true)
    {
        system("cls");
        cout<<"Modificacion de Ventas Detalles"<<endl;
        cout<<"1. Cantidad"<<endl;
        cout<<"2. importe"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Ingrese la opcion: "<<endl;
        cin>>opc;
        switch(opc)
        {
        case 1:
            ven_de_cantidad();
            system("pause");
            break;
        case 2:
            ven_de_imp();
            system("pause");
            break;
        case 0:
            return ;
        default:
            cout<<"Opcion incorrecta. Presione una tecla para continuar";
            system("pause>null");
            break;
        }
    }


};


void ven_de_cantidad()
{
    int cod,can,pos=0;
    Ventas_detalle reg;
    cout<<"ingrese el codigo de la venta a editar"<<endl;
    cin>>cod;
    pos=buscar_art_ventasdetalle(cod);
    if(pos!=-1)
    {
        if(reg.Leer_de_disco(pos)==true)
        {
            cout<<"Leyo"<<endl;
            cout<<"ingrese la nueva cantidad"<<endl;
            cin>>can;
            if(reg.set_cantidad(can)==true)
            {
                if(reg.Modificar_de_disco(pos)==true)
                {
                    cout<<"Modifico"<<endl;
                }
                else
                {
                    cout<<"Erro al Modificar"<<endl;
                }
            }
        }
        else
        {
            cout<<"no se pudo ller de disco"<<endl;
        }
    }


};

void ven_de_imp()
{
    int cod,imp,pos=0;
    Ventas_detalle reg;
    cout<<"ingrese el codigo de la venta a editar"<<endl;
    cin>>cod;
    pos=buscar_art_ventasdetalle(cod);
    if(pos!=-1)
    {
        if(reg.Leer_de_disco(pos)==true)
        {
            cout<<"Leyo"<<endl;
            cout<<"ingrese el nuevo importe"<<endl;
            cin>>imp;
            reg.set_importe(imp);

                if(reg.Modificar_de_disco(pos)==true)
                {
                    cout<<"Modifico"<<endl;
                    system("pause");
                }
                else
                {
                    cout<<"Erro al Modificar"<<endl;
                    system("pause");
                }


        }
        else
        {
            cout<<"no se pudo leer de disco"<<endl;
            system("pause");
        }
    }


};
*/


#endif // MOD_VENTAS_DETALLE_H_INCLUDED
