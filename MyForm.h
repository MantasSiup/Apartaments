#pragma once

#include <fstream>
#include <string>      // reikalinga darbui su eilutėmis
#include <msclr/marshal_cppstd.h> // reikalinga konvertavimui į std::stringą
#include "Apartamentas.h"
#include "PirkimasBeBaldu.h"
#include "Funkcijos.h"
#include "Baldai.h";
#include <sstream>
#include <iomanip>

#define ConvertSystemToStdString msclr::interop::marshal_as<std::string> // reikalinga konvertavimui į std::stringą
#define ConvertStdToSystemString msclr::interop::marshal_as<String^> // reikalinga konvertavimui į system stringą

using namespace std;
const int CMax = 100;
const string PravalymasIrInfo = "IssirinktiBaldai.txt"; //Failo pravalymui ir informacijos surašymui.

namespace P71RSiupieniusBD2019 {

	Apartamentas Apartamentai[CMax];
	int n = 0;
	int k[CMax];
	int KKaina = 0;
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		int Biudzetas;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			
		}
	public:
		MyForm(int Biudzetas)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->Biudzetas = Biudzetas;
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:

	private: System::Windows::Forms::ComboBox^  comboBox1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ComboBox^  comboBox2;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label4;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(103, 128);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 0;
			this->comboBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Location = System::Drawing::Point(100, 94);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(88, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Pasirinkite miestą";
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button1->Location = System::Drawing::Point(26, 386);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(141, 33);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Rinktis baldus";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(298, 128);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 21);
			this->comboBox2->TabIndex = 3;
			this->comboBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::comboBox2_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Location = System::Drawing::Point(485, 131);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(146, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Apartamentų kaina be baldų: ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Location = System::Drawing::Point(295, 94);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(109, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Pasirinkite kvadratûrą";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button2->Location = System::Drawing::Point(716, 386);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(141, 33);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Grįžti";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button3->Location = System::Drawing::Point(218, 386);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(141, 33);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Pirkti be baldų";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20));
			this->label4->Location = System::Drawing::Point(212, 118);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 0);
			this->label4->TabIndex = 9;
			this->label4->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(886, 456);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox1);
			this->Name = L"MyForm";
			this->Text = L"Apartamentų išsirinkimas";
			this->Activated += gcnew System::EventHandler(this, &MyForm::MyForm_Activated);
			this->Deactivate += gcnew System::EventHandler(this, &MyForm::MyForm_Deactivate);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) { //Mygtuko "Rinktis baldus" atliekami veiksmai.
		ofstream dd(PravalymasIrInfo); //Failo išvalymas
		dd << left << setw(20) << "Baldo Pavadinimas: " << "uzimamu kvadratu skaicius:  " << "kaina:" << endl; // Informacijos surašymas
		dd.close();
		String ^Biudzet = ConvertStdToSystemString(to_string(Biudzetas)); //Konvertavimvas į System string.
		Baldai ^ Forma2 = gcnew Baldai(comboBox1->Text, comboBox2->Text, KKaina, Biudzet); //ComboBox1->Text - Miestas, comboBox2->Text - Kvadratų skaičius, KKaina - apartamentų kaina, Biudzet - biudžetas.
		this->Hide();
		Forma2->ShowDialog(); // įjungiama nauja forma
		this->Show();
	}
	private: System::Void MyForm_Activated(System::Object^  sender, System::EventArgs^  e) { //Veiksmai atliekami aktyvavus formą.
		n = 0; // kiekis prilyginamas nuliui.
		//Nuskaitomi apartamentai iš duomenų failo į klasę. ApartamDuomFailas - "Duomenys.txt",
		//Apartamentai[] - apartamentų klasės masyvas, n - miestų kiekis, k[] - apartamentų kiekio masyvas.
		ApartamentuNuskaitymas(ApartamDuomFailas, Apartamentai, n, k);

		//Atrenkami apartamentai pagal biudžetą Apartamentai[] - apartamentų klasės masyvas, n - miestų kiekis, k[] - apartamentų kiekio masyvas, Biudžetas - biudžetas.
		ApartamentuAtrinkimas(Apartamentai, n, k, Biudzetas);
		if (n == 0) //Jei nėra apartamentų kurie atitiktų biudžetą viskas tampa nematoma ir parašomas tekstas per vidurį (label4).
		{
			label4->Visible = true;
			label4->Text = L"Nėra apartamentų, kurie atitiktų jūsų biudžetą. Prašome paspausti mygtuką „Grįžti“ ir įvesti didesnį biudžetą.";
			label4->Size = System::Drawing::Size(483,142);
			button1->Visible = false;
			button3->Visible = false;
			label1->Visible = false;
			label2->Visible = false;
			label3->Visible = false;
			comboBox1->Visible = false;
			comboBox2->Visible = false;
		}
		ifstream fd(ApartamDuomFailas);
		for (int i = 0; i < n; i++)
		{
			comboBox1->Items->Add(ConvertStdToSystemString(Apartamentai[i].ImtiMiesta())); //Pridedami nuskaityti miestai į comboBox1.
		}
	}
	private: System::Void MyForm_Deactivate(System::Object^  sender, System::EventArgs^  e) { //Isvalomi comboBoxai deaktyvavus forma.
		comboBox1->Items->Clear();
		comboBox2->Items->Clear();
	}
	private: System::Void comboBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) { //Issirinkus miesta pridedami į comboBox2 to miesto apartamentų kvadratai.
		for (int i = 0; i < n; i++)
		{
			if (comboBox1->Text == ConvertStdToSystemString(Apartamentai[i].ImtiMiesta()))
			{
				comboBox2->Items->Clear();

				for (int j = 0; j < k[i]; j++)
				{
					comboBox2->Items->Add(ConvertStdToSystemString(to_string(Apartamentai[i].ImtiKv(j))));
				}
				break;

			}
		}

	}
	private: System::Void comboBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) { //Issirinkus kvadratu skaiciu vykdomi veiksmai
		for (int i = 0; i < n; i++)
		{
			if (comboBox1->Text == ConvertStdToSystemString(Apartamentai[i].ImtiMiesta())) //
			{
				for (int j = 0; j < k[i]; j++)
				{
					if (comboBox2->Text == ConvertStdToSystemString(to_string(Apartamentai[i].ImtiKv(j)))) 
					{
						label2->Text = L"Apartamentų kaina be baldų: " + ConvertStdToSystemString(to_string(Apartamentai[i].ImtiKaina(j))) + L" Eurų";
						KKaina = Apartamentai[i].ImtiKaina(j);
						button1->Enabled = true;
						button3->Enabled = true;
					}
				}
			}
		}

	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) { //Mygtuko "Grįžti" atliekami veiksmai.
		this->Hide();
	}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) { //Mygtuko "Pirkti be baldų" atliekami veiksmai
	for (int i = 0; i < n; i++)
	{
		if (comboBox1->Text == ConvertStdToSystemString(Apartamentai[i].ImtiMiesta()))
		{
			for (int j = 0; j < k[i]; j++)
			{
				if (comboBox2->Text == ConvertStdToSystemString(to_string(Apartamentai[i].ImtiKv(j))))
				{
					//Combobox1->Text - Miestas,Apartamentai[i].ImtiKv(j) - kvadratų skaičius, Apartamentai[i].ImtiKaina(j) - apartamentų kaina. 
					PirkimasBeBaldu ^ PirkimoForma = gcnew PirkimasBeBaldu(comboBox1->Text, Apartamentai[i].ImtiKv(j), Apartamentai[i].ImtiKaina(j)); //Sukuriama nauja forma. 
					this->Hide();
					PirkimoForma->ShowDialog(); // įjungiama nauja forma
					this->Show();
}
				}
			}
		}
	}
	
};
}
