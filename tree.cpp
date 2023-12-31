#include <iostream>
using namespace std;
/**
 * Se define la estrucutura para el Arbol Binario.
 * @param data Dato dela rama.
 * @param left Puntero a la siguiente rama.
 * @param right Puntero a la siguiente rama.
 */
struct Tree
{
    int data;
    Tree *left;
    Tree *right;
};
/**
 * Funcion para añadir una rama en el arbol.
 * @param root Hace referencia al nodo principal del arbol.
 * @param value Valor que se agrega al arbol.
 * @param current Variable de apoyo para no modificar el valor de 'root'
 */
void create(Tree *&root, int value)
{

    Tree *current = root; // Se crea un puntero de Tree para guardar 'root'

    if (root != NULL) // Valida si ya existe 'root' (Ya hay al menos un valor)
    {
        if (root->data == value)
        {
            cout << "VALOR YA INGRESADO" << endl;
            return;
        }

        // El dato actual seleccionado del arbol es mayor al valor a ingresar, por ende el valor va a la derecha del rama actual.
        if (root->data > value)
        {
            /**
             * Se valida si el puntero a la izquierda está vacio para así ingresar ahí el nuevo valor, de lo contrario
             * se entiende que ya existe un valor a la izquierda del rama actual.
             */
            if (root->left == NULL)
            {
                Tree *_new = new Tree;
                _new->data = value;
                _new->left = nullptr;
                _new->right = nullptr;
                root->left = _new;
            }
            /**
             * Para cuando ya hay un valor a la izquierda de la Rama acutual, por ende tocar moverse a esa Rama.
             * Se crea un puntero de current, para así no cambiar el valor de 'root', y este nuevo dato se usa para guardar la
             * rama de la izquierda y asi se manda nuevamente para validar.
             */
            else
            {
                Tree *current = new Tree;
                current = root->left;
                create(current, value);
            }
        }

        // El dato actual seleccionado del arbol es menor al valor a ingresar, por ende el valor va a la izquierda de la rama actual.
        else
        {

            /**
             * Se valida si el puntero a la derecha está vacio para así ingresar ahí el nuevo valor, de lo contrario
             * se entiende que ya existe un valor a la derecha de la rama actual.
             */
            if (root->right == NULL)
            {
                Tree *_new = new Tree;
                _new->data = value;
                _new->left = nullptr;
                _new->right = nullptr;
                root->right = _new;
            }
            else
            {
                /**
                 * Para cuando ya hay un valor a la derecha de la Rama acutual, por ende tocar moverse a esa Rama.
                 * Se crea un puntero de current, para así no cambiar el valor de 'root', y esta nueva variable se usa para guardar la
                 * rama de la derecha y asi se manda nuevamente para validar.
                 */
                Tree *current = new Tree;
                current = root->right;  // Nos movemos un nivel en el arbol.
                create(current, value); // Se llama a la misma funcion para así validar.
            }
        }
    }
    /**
     * Algoritmo para cuando se ingresa el primer valor del Arbol.
     */
    else
    {
        Tree *_new = new Tree; // Se inicializa una variable '_new'
        _new->data = value;    // Se actoualiza el dato de _new.data a 'value' (Variable recibida por la funcion)
        _new->left = NULL;     //
        _new->right = NULL;    //
        root = _new;           // Se crea el 'root'
    }
}
/**
 * Funcion para imprimir el arbol.
 * @param root
 * @param level Variable tipo int para saber el nivel del arbol, y así imprimir un espacio.
 *
 * Lo que hace está funcion es llamarse asi misma hasta que llegue a la ultima rama de arbol, empezando por la derecha, cuando llega al final
 * este imprime espacios dependiendo de 'level' (esta varaible aunmenta cada vez que la funcion se llame así misma), despues se imprime el valor del arbol,
 * y se vuelve a llamar así misma, pero ahora pasandole a donde apunta root.left, y vuelve a validar si exisite. si existe empieza otra vez el proceso
 * pero por la parte de la izquierda, cuando esta parte termina se acaba, para dar paso al procedimiento anterior antes de la llamada actual.
 * ()
 *
 * */
void read(Tree *&root, int level)
{
    // Se valida si 'root' está vacia (Sirve tanto para saber si hay datos, o si ya se llegó al final del arbol)
    if (root == NULL)
    {
        return;
    }
    // Se vuelve a llamar a la funcion, pero ahora se le pasa la rama de la derecha, y se le suma un 1 al nivel del arbol
    read(root->right, level + 1);
    // Bucle para impirmir la cantidad de espacios
    for (int i = 0; i < level; i++)
    {
        cout << "       ";
    }
    cout << root->data << "\n";
    // Se vuelve a llamar a la funcion, pero ahora se le pasa la rama de la izquierda, y se le suma un 1 al nivel del arbol.
    read(root->left, level + 1);
}

/**
 *
 *
 */
int main()
{
    Tree *root = NULL;
    int choise, value;

    do
    {
        cout << "OPCIONES: " << endl;
        cout << "0. CreateOne: Para crear un dato en el arbol" << endl;
        cout << "1. ReadAll: Para leer todos los datos del arbol" << endl;
        cout << "Ingrese la opcion que desea: ";
        cin >> choise;
        switch (choise)
        {
        case 0:
            cout << "Numero a ingresar: ";
            cin >> value;
            create(root, value);
            /* create(root, 10);
             create(root, 5);
             create(root, 15);
             create(root, 3);
             create(root, 8);
             create(root, 14);
             create(root, 18);
             create(root, 2);
             create(root, 4);
             create(root, 6);
             create(root, 8);
             create(root, 12);
             create(root, 13);
             create(root, 16);
             create(root, 19);
             create(root, 20);
             create(root, 1);
             create(root, 0);*/
            break;
        case 1:
            read(root, 0);
            break;
        default:
            cout << "Opcion invalida";
            break;
        }
        cout << "\nOpciones: \n"
             << "0:Finalizar 1:Seguir" << endl;
        cin >> choise;
    } while (true);
}