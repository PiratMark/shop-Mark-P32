#include <iostream>
#include <string>
#include <limits>
// Пиратская Бухта продажа море продуктов 

//Глобальны масивы 
int size = 10;
int* idArr = new int[size];
std::string* nameArr = new std::string[size];
int* countArr = new int[size];
double* priceArr = new double[size];




template <typename ArrType>
void FillArray(ArrType staticArr, ArrType dinArr, int size);


//основные фукции 
void Start();
void DeleteMainArrays();
void CreateStorage();
void ShowStorage();
void Shop();

int main()
{
	setlocale(LC_ALL, "ru");
	Start();
	

	delete[]idArr;
	delete[]nameArr;
	delete[]countArr;
	delete[]priceArr;
	return 0;
}

void Start()
{
	std::cout << "\t\tДобро пожаловать в Пиратскую Бухту\n\n ";
	std::string adminLogin = "Pirat";
	std::string adminPassword = "Mark";
	std::string login, password;
	int choose;
	bool exit = false;
	do
	{
		std::cout << "Введите логин: ";
		std::getline(std::cin, login);
		std::cout << "Введите пароль: ";
		std::getline(std::cin, password);

		if (login != adminLogin || password != adminPassword)
		{
			std::cerr << "Неверный логин или пароль\n";
			std::cout << "Попробовать ещё раз ? \n1 - Да\n2 - Выход из програмы\n";
			std::cin >> choose;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (choose == 2)
			{
				exit = true;
			}
		}
		else
		{
			exit = true;
			int chooseStorageType;
			do
			{
				std::cout << "Введите формат склада: \n 1 - готовый склад\n 2 - создать склад вручную\n";
				std::cin >> chooseStorageType;
			} while (chooseStorageType < 1 || chooseStorageType > 2);
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (chooseStorageType == 1)
			{
				CreateStorage();
				Shop();
			}
			else if (chooseStorageType == 2)
			{
				std::cout << "В разработке";
			}
			else
			{
				std::cerr << "Error chooseStorageType";
			}
		}
	} while (!exit);

}

void DeleteMainArrays()
{
	delete[]idArr;
	delete[]nameArr;
	delete[]countArr;
	delete[]priceArr;
}

void CreateStorage()
{
	const int staticSize = 10;
	int id[staticSize]{ 0,1,2,3,4,5,6,7,8,9 };
	std::string name[staticSize]{"Креветки\t\t\t\t","Устрица Розавая Джоли\t\t\t",
	"Осьминоги молодые очищеные мини\t","Мидии Целые в раковинах\t\t","Крабовые палочки\t\t\t",
	"Морской Ёж\t\t\t\t", "Кальмар Командорский\t\t\t", "Русалчина\t\t\t\t",
	"Морской Краб\t\t\t\t", "Улитка виноградная фаршированная\t", };
	int count[staticSize]{15,5,8,4,40,2,3,1,7,96 };
	double price[staticSize]{299.0,229.0,230.0,529.0,120.0,99.0,
	389.0,1999.0,623.0,699.0 };


		FillArray(id, idArr, staticSize);
		FillArray(name, nameArr, staticSize);
		FillArray(count, countArr, staticSize);
		FillArray(price, priceArr, staticSize);

}

void ShowStorage()
{
	std::cout << "ID\tНазвание товара\t\t\t\tКол-во\tЦена\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << idArr[i] << " " << nameArr[i] << "\t" <<
			countArr[i] <<"\t" << priceArr[i] << "\n" ;
	}
}

void Shop()
{
	while (true)
	{
		int choose;
		do
		{
			std::cout << "1 - Показать склад\n";
			std::cout << "2 - Начять продажу\n";
			std::cout << "3 - Изменить цену\n";
			std::cout << "4 - Списать товар\n";
			std::cout << "5 - Пополнить товар\n";
			std::cout << "6 - Изменить склад\n";
			std::cout << "0 - Закончить смену\n";
		std::cin >> choose;
		} while (choose < 0 || choose > 0);

		if (choose == 1)
		{
			ShowStorage();
		}
		else if(choose == 2)
		{

		}
		else if (choose == 3)
		{

		}
		else if (choose == 4)
		{

		}
		else if (choose == 5)
		{

		}
		else if (choose == 6)
		{


		}
		else if (choose == 6)
		{

		}
		else if (choose == 0)
		{
			break;
		}
		else  
		{
			std::cerr << "Error";
		}
	}
}
template <typename ArrType>
void FillArray(ArrType staticArr, ArrType dinArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		dinArr[i] = staticArr[i];
	}
}
