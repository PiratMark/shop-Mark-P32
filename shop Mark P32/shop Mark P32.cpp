#include <iostream>
#include <string>
#include <limits>
// Пиратская Бухта продажа море продуктов 

//Глобальны масивы 
int size = 10;
int receiptSize = 1;
double cash = 35376.00;
double cashIncome = 0, cardIncome = 0, totalIncome = 0;
int* idArr = new int[size];

std::string* nameArr = new std::string[size];
int* CountArr = new int[size];

double* priceArr = new double[size];

template <typename Arr>
void FillArr(Arr staticArr, Arr dinArr, int size);

std::string* nameReceiptArr = new std::string[receiptSize];
int* CountReceiptArr = new int[receiptSize];
double* priceReceiptArr = new double[receiptSize];



//основные фукции 
void Start();
void Selling();
void AddElementToReceipt(int id, int count);
void DeleteMainArr();
void CreateStorage();
void ShowStorage();
void PrintReceipt();
void Shop();
void ChangPrice();
void RemoveFromStorage();
void AddToStorage();
void ChangeStorage();
void AddElementToEnd();
void DeleteElementByIndex();
void CashStatus();

int main()
{
	setlocale(LC_ALL, "ru");
	Start();
	CreateStorage();
	ShowStorage();
	DeleteMainArr();


	delete[]idArr;
	delete[]nameArr;
	delete[]CountArr;
	delete[]priceArr;
	return 0;
}

void ShowStorage()
{
	std::cout << "ID\tНазвание товара\t\t\t\tКол-во\tЦена\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << idArr[i] << " " << nameArr[i] << "\t" <<
			CountArr[i] << "\t" << priceArr[i] << "\n";
	}
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
		std::cout << " Введите пароль: ";
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
				std::cout << "Введите формат склада: \n1 - готовый склад\n2 - создать склад вручную\n";
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

void AddElementToReceipt(int id, int count)
{
	std::string* nameReceiptArrTemp = new std::string[receiptSize];

	int* CountReceiptArrTemp = new int[receiptSize];

	double* priceReceiptArrTemp = new double[receiptSize];
	for (int i = 0; i < receiptSize; i++)
	{
		nameReceiptArrTemp[i] = nameReceiptArr[i];
		CountReceiptArrTemp[i] = CountReceiptArr[i];
		priceReceiptArrTemp[i] = priceReceiptArr[i];
	}
	delete[]nameArr;
	delete[]CountArr;
	delete[]priceArr;
	receiptSize++;

	nameReceiptArr = new std::string[receiptSize];
	CountReceiptArr = new int[receiptSize];
	priceReceiptArr = new double[receiptSize];
	for (int i = 0; i < receiptSize - 1; i++)
	{
		nameReceiptArr[i] = nameReceiptArrTemp[i];
		CountReceiptArr[i] = CountReceiptArrTemp[i];
		priceReceiptArr[i] = priceReceiptArrTemp[i];

		nameReceiptArr[i] = nameReceiptArrTemp[i];
		CountReceiptArr[i] = CountReceiptArrTemp[i];
		priceReceiptArr[i] = priceReceiptArrTemp[i];

	}


	nameReceiptArr[receiptSize - 1] = nameArr[id - 1];
	CountReceiptArr[receiptSize - 1] = count;
	priceReceiptArr[receiptSize - 1] = priceArr[id - 1] * count;
	CountArr[id - 1] -= count;

	
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
			std::cout << "7 - Показать кассу\n";
			std::cout << "0 - Закончить смену\n";
			std::cin >> choose;
		} while (choose < 0 || choose > 6);

		if (choose == 1)
		{
			ShowStorage();
		}
		else if (choose == 2)
		{
			Selling();
		}
		else if (choose == 3)
		{
			ChangPrice();
		}
		else if (choose == 4)
		{
			RemoveFromStorage();
		}
		else if (choose == 5)
		{
			AddToStorage();
		}
		else if (choose == 6)
		{
			ChangeStorage();
		}
		else if (choose == 7)
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

void DeleteMainArr()
{
	delete[]idArr;
	delete[]nameArr;
	delete[]CountArr;
	delete[]priceArr;
}

void CreateStorage()
{
	const int staticSize = 10;
	int id[staticSize]{ 0,1,2,3,4,5,6,7,8,9 };
	std::string name[staticSize]{ "Креветки\t\t\t\t","Устрица Розавая Джоли\t\t\t",
	"Осьминоги молодые очищеные мини\t","Мидии Целые в раковинах\t\t","Крабовые палочки\t\t\t",
	"Морской Ёж\t\t\t\t", "Кальмар Командорский\t\t\t", "Русалчина\t\t\t\t",
	"Морской Краб\t\t\t\t", "Улитка виноградная фаршированная\t", };
	int count[staticSize]{ 15,5,8,4,40,2,3,1,7,96 };
	double price[staticSize]{ 299.0,229.0,230.0,529.0,120.0,99.0,
	389.0,1999.0,623.0,699.0 };

	FillArr(id, idArr, staticSize);
	FillArr(name, nameArr, staticSize);
	FillArr(count, CountArr, staticSize);
	FillArr(price, priceArr, staticSize);

}

void PrintReceipt()
{
	std::cout << "Название\t\t\tКол-во\tЦена\n";
	for (int i = 0; i < receiptSize; i++)
	{
		std::cout << nameReceiptArr[i] << "\t\t" << CountReceiptArr[i] << "\t" << priceReceiptArr[i] << "\n";
	}std::cout << "\n";
}

void Selling()
{
	bool isFirst = true;
	int chooseId, chooseCount, confirm;
	double totalSum = 0;
	while (true)
	{
		totalSum = 0;
		do
		{
			std::cout << "Введите id товара: ";
			std::cin >> chooseId;
			if (chooseId < 1 || chooseId > size)
			{
				std::cerr << "Данного товара нет\n";
			}
			if (CountArr[chooseId - 1] > 0)
			{
				while (true)
				{
					std::cout << "\nВыбраный товар: " << nameArr[chooseId - 1] << "\n";
					std::cout << "Кол-во данного товара складу: " << CountArr[chooseId - 1];
					std::cout << "Введите кол-во товара: ";
					std::cin >> chooseCount;
					if (chooseCount < 1 || chooseCount > CountArr[chooseId - 1])
					{
						std::cerr << "Error\n";
					}
					else
					{
						break;
					}
				}
			}
			else
			{
				std::cerr << "Товара на складе нет\n";
				continue;
			}
			std::cout << "\n Товар: " << nameArr[chooseId - 1] << "\t Кол-во: " << chooseCount;
			std::cout << "\n 1 - Подтвердить\n 2 - Отмена: ";
			std::cin >> confirm;
			if (confirm == 1)
			{
				if (isFirst)
				{
					nameReceiptArr[receiptSize - 1] = nameArr[chooseId - 1];
					CountReceiptArr[receiptSize - 1] = chooseCount;
					priceReceiptArr[receiptSize - 1] = priceArr[chooseId - 1] * chooseCount;
					CountArr[chooseId - 1] -= chooseCount;
					totalSum += priceArr[chooseId - 1] * chooseCount;
					isFirst = false;
				}
				else
				{
					AddElementToReceipt(chooseId, chooseCount);
					totalSum += priceArr[chooseId - 1] * chooseCount;
				}
			}
			else
			{
				continue;
			}
			std::cout << "Купить ещё 1 товар?: \n";
			std::cout << "1 - Да\n 2 - Закончить покупки\n";
			std::cin >> confirm;
			if (confirm == 1)
			{
				continue;
			}
			break;
		}
		while (true);
		{
			PrintReceipt();
		}
		//скидки сделай сука ленивая >:( 
		int pay = 0;
		std::cout << "\n\n\n";
		do
		{
			std::cout << "1 - Наличные\n2 - Оплата картой\n\n";
			std::cin >> pay;
		} while (pay < 1 || pay > 2);
		if (pay == 1)
		{
			cash += totalSum;
			cashIncome += totalSum;
		}
		else if (pay == 2)
		{
			cardIncome += totalSum;
		}
		

	}
}

void ChangPrice()
{
	int id;
	double newPrice;
	do
	{
		std::cout << "Введите ID товара для изменения цены: ";
		std::cin >> id;
	} while (id < 1 || id > idArr[size - 1]);

	std::cout << "\n\nВыбран товар: " << nameArr[id - 1] << " = " << priceArr[id - 1];
	do
	{
		std::cout << "\nВведите новоу цену: ";
		std::cin >> newPrice;

	} while (newPrice < 0.01 || newPrice > 10000.0);
	priceArr[id - 1] = newPrice;
	std::cout << "\nЦена успешно изменена\n\n";

}

void RemoveFromStorage()
{
	int id;
	int Count;
	do
	{
		std::cout << "Введите ID товара списания: ";
		std::cin >> id;
	} while (id < 1 || id > idArr[size - 1]);

	std::cout << "\n\nВыбран товар: " << nameArr[id - 1] << " = " << CountArr[id - 1]
		<< "штук\n\n";
	do
	{
		std::cout << "\nВведите кол-во товара: ";
		std::cin >> Count;
	} while (Count < 0 || CountArr[id - 1]);
	priceArr[id - 1] -= CountArr[id - 1];
	std::cout << "\nТовар успешно списан\n\n";
}

void AddToStorage()
{
	int id;
	int Count;
	do
	{
		std::cout << "Введите ID товара списания: ";
		std::cin >> id;
	} while (id < 1 || id > idArr[size - 1]);

	std::cout << "\n\nВыбран товар: " << nameArr[id - 1] << " = " << CountArr[id - 1]
		<< "штук\n\n";
	do
	{
		std::cout << "\nВведите кол-во товара: ";
		std::cin >> Count;
	} while (Count < 0 || CountArr[id - 1]);
	priceArr[id - 1] += CountArr[id - 1];
	std::cout << "\nТовар успешно списан\n\n";
}

void ChangeStorage()
{
	int choose;
	do
	{
		std::cout << "1 - Добавить товар в склад\n";
		std::cout << "2 - Убрать товар со склада\n";
		std::cout << "0 - Выход\n";
		std::cin >> choose;
	} while (choose < 0 || choose > 2);
	if (choose == 1)
	{
		AddElementToEnd();
	}
	else if (choose == 2)
	{
		DeleteElementByIndex();
	}
	else
	{
		std::cout << "Выход";
	}



}

void AddElementToEnd()
{
	int* idArrTemp = new int[size];
	std::string* nameArrTemp = new std::string[size];
	int* CountArrTemp = new int[size];
	double* priceArrTemp = new double[size];
	for (int i = 0; i < size; i++)
	{
		nameArrTemp[i] = nameArr[i];
		CountArrTemp[i] = CountArr[i];
		priceArrTemp[i] = priceArr[i];
	}
	delete[]idArr;
	delete[]nameArr;
	delete[]CountArr;
	delete[]priceArr;

	size++;
	idArr = new int[size];
	nameArr = new std::string[size];
	CountArr = new int[size];
	priceArr = new double[size];
	for (int i = 0; i < size - 1; i++)
	{
		idArr[i] = idArrTemp[i];
		nameArr[i] = nameArrTemp[i];
		CountArr[i] = CountArrTemp[i];
		priceArr[i] = priceArrTemp[i];
	}
	idArr[size - 1] = size;
	std::cout << "Введите имя нового товара: \n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, nameArr[size - 1], '\n');
	std::cout << "Введите кол-во нового товара: \n";
	std::cin >> CountArr[size - 1];
	std::cout << "Введите цену  нового товара: \n";
	std::cin >> priceArr[size - 1];
	delete[]idArr;
	delete[]nameArr;
	delete[]CountArr;
	delete[]priceArr;
}

void DeleteElementByIndex()
{
	int* idArrTemp = new int[size];
	std::string* nameArrTemp = new std::string[size];
	int* CountArrTemp = new int[size];
	double* priceArrTemp = new double[size];
	for (int i = 0; i < size; i++)
	{
		nameArrTemp[i] = nameArr[i];
		CountArrTemp[i] = CountArr[i];
		priceArrTemp[i] = priceArr[i];
	}
	delete[]idArr;
	delete[]nameArr;
	delete[]CountArr;
	delete[]priceArr;

	for (int i = 0; i < size - 1; i++)
	{
		idArr[i] = idArrTemp[i];
		nameArr[i] = nameArrTemp[i];
		CountArr[i] = CountArrTemp[i];
		priceArr[i] = priceArrTemp[i];
	}

	size--;
	idArr = new int[size];
	nameArr = new std::string[size];
	CountArr = new int[size];
	priceArr = new double[size];
	int index = 0;
	do
	{
		std::cout << "Введите id товара для удаления";
		std::cin >> index;
	} while (index < 1 || index > size);
	
	for (int i = 0, j = 0; i < index, j < index; i++, j++)
	{
		if (i == index - 1)
		{
			i++;
			idArr[j] = idArrTemp[j];
			nameArr[j] = nameArrTemp[i];
			CountArr[j] = CountArrTemp[i];
			priceArr[j] = priceArrTemp[i];
		}
		else
		{
			idArr[j] = idArrTemp[j];
			nameArr[j] = nameArrTemp[i];
			CountArr[j] = CountArrTemp[i];
			priceArr[j] = priceArrTemp[i];
		}
	}
	delete[]idArr;
	delete[]nameArr;
	delete[]CountArr;
	delete[]priceArr;
}

void CashStatus()
{
	totalIncome = cashIncome + cardIncome;
	std::cout << "Наличные в кассе: " << cash << "\nВыручка за наличные: "
	<< cashIncome << "\nВыручка по безналу: "
	<< cardIncome << "\n\nИтоговая выручка за смену: "
	<< totalIncome << "\n\n";
}

template<typename Arr>
void FillArr(Arr staticArr, Arr dinArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		dinArr[i] = staticArr[i];
	}
}
