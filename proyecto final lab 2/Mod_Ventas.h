#ifndef MOD_VENTAS_H_INCLUDED
#define MOD_VENTAS_H_INCLUDED
void Mod_ventas()
{
    int opc;
    while(true)
    {
        system("cls");
        cout<<"Modificaci?n de Ventas"<<endl;
        cout<<"1. Dni.Empleado."<<endl;
        cout<<"2. Dni.Cliente."<<endl;
        cout<<"3. Fecha."<<endl;
        cout<<"0. Salir."<<endl;
        cout<<"Ingrese la opci?n: "<<endl;
        cin>>opc;
        switch(opc)
        {
        case 1:
            ven_emp();
            system("pause");
            break;
        case 2:
            ven_cli();
            system("pause");
            break;
        case 3:
            ven_fecha();
            system("pause");
            break;
        case 0:
            return ;
        default:
            cout<<"Opci?n incorrecta. Presione una tecla para continuar.";
            system("pause>null");
            break;
        }
    }

};

void ven_emp()
{
    system("cls");
    int cod,dni,pos=-1;
    Ventas reg;
    cout<<"Ingrese el c?digo de la venta a editar."<<endl;
    cin>>cod;
    pos=buscar_codventa(cod);
    if(pos!=-1)
    {
        if(reg.Leer_de_disco(pos)==true)
        {

            cout<<"Ingrese el nuevo dni del empleado."<<endl;
            cin>>dni;
            pos=buscar_dni_empleado(dni);
            if(pos!=-1){
                reg.set_dni_emlpeado(dni);
                if(reg.Modificar_de_disco(pos)==true)
                {
                    cout<<"Se modific?."<<endl;
                }
                else
                {
                    cout<<"Error al modificar."<<endl;
                }
            }

        }
        else
        {
            cout<<"No se pudo leer de disco."<<endl;
        }

    }
    else
    {
        cout<<"No se encontr? el codigo de venta."<<endl;
        return;
    }


};

void ven_cli()
{
    system("cls");
    int cod,dni,pos=-1;
    Ventas reg;
    cout<<"Ingrese el codigo de la venta a editar."<<endl;
    cin>>cod;
    pos=buscar_codventa(cod);
    if(pos!=-1)
    {
        if(reg.Leer_de_disco(pos)==true)
        {
            cout<<"Ingrese el nuevo dni del cliente."<<endl;
            cin>>dni;
            pos=buscar_dni(dni);
            if(pos!=-1){
               reg.set_dni_cliente(dni);
            {
                if(reg.Modificar_de_disco(pos)==true)
                {
                    cout<<"Se modific?."<<endl;
                    system("pause");
                }
                else
                {
                    cout<<"Error al Modificar."<<endl;
                    system("pause");
                }
            }

            }

        }
        else
        {
            cout<<"No se pudo leer de disco."<<endl;
            system("pause");
        }


    }
    else
    {
        cout<<"No se encontr? el c?digo de venta."<<endl;
        return;
    }

};


void ven_fecha()
{
    system("cls");
    int cod,dia,mes,anio,pos=-1;
    Ventas reg;
    cout<<"Ingrese el c?digo de la venta a editar."<<endl;
    cin>>cod;
    pos=buscar_codventa(cod);
    if(pos!=-1)
    {
        if(reg.Leer_de_disco(pos)==true)
        {

            cout<<"Ingrese la  nueva fecha."<<endl;
            cout<<"Fecha"<<endl;
            cout<<"Dia: "<<endl;
            cin>>dia;
            cout<<"Mes: "<<endl;
            cin>>mes;
            cout<<"A?o: "<<endl;
            cin>>anio;
            pos=comprobar_fecha(dia,mes,anio);
            if(pos!=-1){
            reg.Modificar_fecha(dia,mes,anio);
            if(reg.Modificar_de_disco(pos)==true)
            {
                cout<<"Se modific?."<<endl;
            }
            else
            {
                cout<<"Error al Modificar."<<endl;
            }

            }

        }
        else
        {
            cout<<"No se pudo leer de disco."<<endl;
        }

    }
    else
    {
        cout<<"No se encontr? el codigo de venta."<<endl;
        return;
    }

};
#endif // MOD_VENTAS_H_INCLUDED
