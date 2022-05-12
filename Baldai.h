#pragma once

#include <fstream>
#include <string>      // Reikalinga darbui su eilutėmis
#include <msclr/marshal_cppstd.h> // Reikalinga konvertavimui į std::stringą
#include "Baldas.h" // Baldų klasės funkcijos
#include "Apartamentas.h" // Apartamentų klasės funkcijos
#include "Pirkimas.h" // Reikalinga pirkimo formos atidarymui
#include "Funkcijos.h" //Čia surašytos funkcijos

#define ConvertSystemToStdString msclr::interop::marshal_as<std::string> // Reikalinga konvertavimui į std::stringą
#define ConvertStdToSystemString msclr::interop::marshal_as<String^> // Reikalinga konvertavimui į ^stringą

using namespace std;

const int CmMax = 100; //Baldų klasės maksimalus kiekis
const string ApartamDuomFailas = "Data/Duomenys.txt"; //Šiame faile yra surašyti apartamentų duomenys - miestas, kvadratų skaičius, kaina.
const string BalduDuomFailas = "Data/Baldai.txt"; //Šiame faile yra surašyti baldų duomenys - pavadinimas, užimamų kvadratų skaičius, kaina.
const string RikiuotuBalduFailas = "RikiuotiBaldai.txt"; //Šiame faile yra spausdinimas surikiuotų baldų sąrašas (Jei rikiavimas buvo vykdomas).
const string IssirinktuBalduFailas = "IssirinktiBaldai.txt"; //Šiame faile yra spausdinami baldai, kuriuos išsirinko vartotojas.

namespace P71RSiupieniusBD2019 {

	int m = 0; // m - baldų kiekis
	Baldas BaldaiVisi[CmMax]; //Baldų klasės masyvas.
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Baldai
	/// </summary>
	public ref class Baldai : public System::Windows::Forms::Form
	{
	public :
		String ^Temp; // Maksimalus kvadratų skaičius
		String ^Biudzetas; //Biudzetas
		String ^Miestas; // Miestas
		int Kkaina; // Apartamentų kaina.
	private: System::Windows::Forms::Button^  button2;
	public:
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::ProgressBar^  progressBar2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
			 
	public:
		Baldai(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		Baldai(String ^Miestas, String ^Temp, int Kkaina, String ^Biudzetas) //Naujas formos konstruktorius(reikalingas duomenų perdavimui iš formos į formą). Miestas - miestas, Temp - maksimalus kvadratų skaičius, KKaina - apartamentų kaina
																			 //Biudzetas - biudžetas
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->Temp = Temp; //Temp - maksimalus kvadratų skaičius.
			this->Kkaina = Kkaina; // KKaina - aparatamentų kaina.
			this->Biudzetas = Biudzetas; //Biudzetas - Biudžetas
			this->Miestas = Miestas; //Miestas - miestas
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Baldai()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;




	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Baldai::typeid));
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->progressBar2 = (gcnew System::Windows::Forms::ProgressBar());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Consolas", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->richTextBox1->Location = System::Drawing::Point(26, 30);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(276, 234);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(443, 78);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(50, 20);
			this->numericUpDown1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button1->Location = System::Drawing::Point(408, 128);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(118, 33);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Pasirinkti";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Baldai::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(333, 200);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(109, 19);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Rikiavimo būdai:";
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(26, 307);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(276, 26);
			this->progressBar1->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->label2->Location = System::Drawing::Point(163, 314);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(19, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"90";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->label3->Location = System::Drawing::Point(140, 314);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(21, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"0 /";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(79, 283);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(165, 19);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Galimas kvadratų skaičius";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button2->Location = System::Drawing::Point(408, 300);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(118, 33);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Rikiuoti";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Baldai::button2_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Rikiuoti baldus pagal kaina didejanciai", L"Rikiuoti baldus pagal kaina mazejanciai",
					L"Rikiuoti baldus pagal kvadratu skaiciu didejanciai", L"Rikiuoti baldus pagal kvadratu skaiciu mazejanciai"
			});
			this->comboBox1->Location = System::Drawing::Point(337, 243);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(248, 21);
			this->comboBox1->TabIndex = 9;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(333, 44);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(193, 19);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Iveskite norimo baldo indeksą:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(129, 376);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(67, 19);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Biudžetas";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->label7->Location = System::Drawing::Point(116, 405);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(51, 13);
			this->label7->TabIndex = 13;
			this->label7->Text = L"100000 /";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->label8->Location = System::Drawing::Point(163, 405);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(43, 13);
			this->label8->TabIndex = 12;
			this->label8->Text = L"100000";
			// 
			// progressBar2
			// 
			this->progressBar2->Location = System::Drawing::Point(26, 398);
			this->progressBar2->Maximum = 100000;
			this->progressBar2->Name = L"progressBar2";
			this->progressBar2->Size = System::Drawing::Size(276, 26);
			this->progressBar2->TabIndex = 11;
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button3->Location = System::Drawing::Point(485, 498);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(118, 33);
			this->button3->TabIndex = 15;
			this->button3->Text = L"Grįžti";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Baldai::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button4->Location = System::Drawing::Point(64, 498);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(118, 33);
			this->button4->TabIndex = 16;
			this->button4->Text = L"Tęsti";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Baldai::button4_Click);
			// 
			// Baldai
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(642, 566);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->progressBar2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->richTextBox1);
			this->Name = L"Baldai";
			this->Text = L"Baldų išsirinkimas";
			this->Activated += gcnew System::EventHandler(this, &Baldai::Baldai_Activated);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Baldai_Activated(System::Object^  sender, System::EventArgs^  e) { //Veiksmai atliekami aktyvavus Baldai.h formą

		if (richTextBox1->Text == "") //Tikrinama ar anksčiau nebuvo prirašyta į richTextBoxą, kad nebūtų perkrova.
		{
			BalduNuskaitymasIKlase(BalduDuomFailas, BaldaiVisi, m); //Baldų nuskaitymas į baldų klasę. BalduDuomFailas - "Baldai.txt", BaldaiVisi - klasės struktūrų masyvas, m - kiekis.
			string tekstas = ""; //Stringo pravalymas.
			BalduNuskaitymasIStringa(BalduDuomFailas, tekstas); // BalduDuomFailas - "Baldai.txt", tekstas - stringas, kuriame laikomi baldų duomenys.
			richTextBox1->Text = ConvertStdToSystemString(tekstas); //Baldų duomenys įrašomi į richTextBox'ą.

			String ^tempas = this->Temp; // Konvertavimas masksimalaus kvadratų skaičiaus į ^Stringą
			String ^Biudzet = this->Biudzetas; // Konvertavimas biudžeto į ^Stringą
			String ^Miestelis = this->Miestas; //Konvertavimas miesto į ^Stringą

			string Laikinas; // Reikalingas konveravimui iš ^String į std::string.
			string Laikinas1; // Reikalingas konveravimui iš ^String į std::string.
			Laikinas = ConvertSystemToStdString(tempas); // Konvertavimas iš ^String į std::string.
			Laikinas1 = ConvertSystemToStdString(Biudzet); // iš ^String į std::string.
			int ApartamentoKaina = this->Kkaina; // Apartamento kainos konvertavimas į paprastą int.
			progressBar2->Value = ApartamentoKaina; // ProgressBar2 suteikiama reikšmė apartamentų kaina. Tai reikalinga, kad vartotojas matytų, kiek pinigų iš savo biudžeto išnaudojo.
			progressBar1->Maximum = stoi(Laikinas); // ProgressBar1 priskiriama maksimali reikšmė - maksimalus kvadratų skaičiaus.
			progressBar2->Maximum = stoi(Laikinas1); // ProgressBar1 priskiriama maksimali reikšmė - biudžetas.
			label2->Text = tempas; // Į label2 įrašomas maksimalus kvadratų skaičius (Atitinka maksimalią progressbar1 reikšmę).
			label8->Text = Biudzet; // Į label8 įrašomas galimas biudžetas (Atitinka maksimalią progressbar2 reikšmę).
			label7->Text = ConvertStdToSystemString(to_string(progressBar2->Value)) + " /"; // Į label7 įrašoma apartamentų kaina(Atitinka progressbar2 reikšmę).
		}


	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		int sk = -1; //Indeksas reikalingas baldų išsirinkimui.
		sk = (int)numericUpDown1->Value;

		if (sk >= 0 && sk < m) //Tikrinama ar yra baldas su tokiu indekso numeriu.
		{
			if ((progressBar1->Value + BaldaiVisi[sk].ImtiKv()) <= progressBar1->Maximum) // Tikrinama ar baldas neužims per daug vietos.
			{
				if ((progressBar2->Value + BaldaiVisi[sk].ImtiKaina()) <= progressBar2->Maximum) // Tikrinama ar užteks biudžeto norint įsigyti baldą.
			{
				progressBar2->Value += BaldaiVisi[sk].ImtiKaina(); // Prie progressBar2 pridedama baldo kaina.
				label7->Text = ConvertStdToSystemString(to_string(progressBar2->Value)) + " /"; // Įrašoma progressbar2 reikšmė, kad būtų aišku vartotojui.
				progressBar1->Value += BaldaiVisi[sk].ImtiKv(); // Prie progressBar1 pridedama baldo užimama vieta.
				// Išrinktų baldų spausdinimas į failą.
				// IssirinktuBalduSpausdinimas - "IsrinktiBaldai.txt",  BaldaiVisi[] - baldų klasės masyvas, sk - išsirinkto baldo indeksas.
				IssirinktuBalduSpausdinimasIFaila(IssirinktuBalduFailas, BaldaiVisi, sk);
				label3->Text = ConvertStdToSystemString(to_string(progressBar1->Value)) + " /";  // Įrašoma progressbar1 reikšmė, kad būtų aišku vartotojui.
				}
			else
				MessageBox::Show("Tai virsys jusu biudzeta!", "Ispejimas", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			}
			else 
				MessageBox::Show("Apartamentuose nera tiek vietos!", "Ispejimas", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);

			
		}
		else
			MessageBox::Show("Nera baldo su tokiu indekso numeriu!", "Ispejimas", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) { //Veiksmai atliekami paspaudus mygtuką "Rikiuoti"
	
		string RikiavimoTipas; 

		RikiavimoTipas = ConvertSystemToStdString(comboBox1->Text); //Priskiriamas išsirinktas rikiavimo tipas.

		if (comboBox1->Text == "Rikiuoti baldus pagal kaina didejanciai") //Tikrinama ar rikiuoti baldus reikės pagal kainą didėjančiai.
		{
			BalduRikiavimasPagalKainaDidejanciai(BaldaiVisi, m); // Vykdoma funkcija, kuri surikiuoja baldus pagal kainą didėjančiai. BaldaiVisi - klasių masyvas, m - kiekis.
			BalduSpausdinimasIFaila(RikiuotuBalduFailas, BaldaiVisi, m);// Surikiuoti baldai spausdinami į failą. BaldaiVisi - klasių masyvas, m - kiekis, RikiuotuBalduFailas - "RikiuotiBaldai.txt."
			string tekstas = ""; // Sukuriamas stringas, kuriame bus laikomi surikiuoti baldai.
			BalduNuskaitymasIStringa(RikiuotuBalduFailas, tekstas); // RikiuotuBaldų failas - "RikiuotiBaldai.txt", tekstas - stringas, kuria laikomi surikiuoti baldai.
			richTextBox1->Text = ConvertStdToSystemString(tekstas); // Surikiuoti baldai įrašomi į richTextBox1, kad matytų vartotojas.

		}
		else if (comboBox1->Text == "Rikiuoti baldus pagal kaina mazejanciai") // Tikrinama ar rikiuoti baldus reikės pagal kainą mažėjančiai.
			{
				BalduRikiavimasPagalKainaMazejanciai(BaldaiVisi, m); // Vykdoma funkcija, kuri surikiuoja baldus pagal kainą mažėjančiai. BaldaiVisi - klasių masyvas, m - kiekis.
				BalduSpausdinimasIFaila(RikiuotuBalduFailas, BaldaiVisi, m); // Surikiuoti baldai spausdinami į failą. BaldaiVisi - klasių masyvas, m - kiekis, RikiuotuBalduFailas - "RikiuotiBaldai.txt."
				string tekstas = ""; // Sukuriamas stringas, kuriame bus laikomi surikiuoti baldai.
				BalduNuskaitymasIStringa(RikiuotuBalduFailas, tekstas); // RikiuotuBaldų failas - "RikiuotiBaldai.txt", tekstas - stringas, kuria laikomi surikiuoti baldai.
				richTextBox1->Text = ConvertStdToSystemString(tekstas); // Surikiuoti baldai įrašomi į richTextBox1, kad matytų vartotojas.

			}
		else if (comboBox1->Text == "Rikiuoti baldus pagal kvadratu skaiciu didejanciai") // Tikrinama ar rikiuoti baldus reikės pagal kvadratų skaičių didėjančiai.
			{
				BalduRikiavimasPagalKvadratusDidejanciai(BaldaiVisi, m); // Vykdoma funkcija, kuri surikiuoja baldus pagal kvadratų skaičių didėjančiai. BaldaiVisi - klasių masyvas, m - kiekis.
				BalduSpausdinimasIFaila(RikiuotuBalduFailas, BaldaiVisi, m);// Surikiuoti baldai spausdinami į failą. BaldaiVisi - klasių masyvas, m - kiekis, RikiuotuBalduFailas - "RikiuotiBaldai.txt."
				string tekstas = ""; // Sukuriamas stringas, kuriame bus laikomi surikiuoti baldai.
				BalduNuskaitymasIStringa(RikiuotuBalduFailas, tekstas);// RikiuotuBaldų failas - "RikiuotiBaldai.txt", tekstas - stringas, kuria laikomi surikiuoti baldai.
				richTextBox1->Text = ConvertStdToSystemString(tekstas); // Surikiuoti baldai įrašomi į richTextBox1, kad matytų vartotojas.

			}
		else if (comboBox1->Text == "Rikiuoti baldus pagal kvadratu skaiciu mazejanciai") // Tikrinama ar rikiuoti baldus reikės pagal kvadratų skaičių mažęjančiai.
			{
				BalduRikiavimasPagalKvadratusMazejanciai(BaldaiVisi, m); // Vykdoma funkcija, kuri surikiuoja baldus pagal kvadratų skaičių mažėjančiai. BaldaiVisi - klasių masyvas, m - kiekis.
				BalduSpausdinimasIFaila(RikiuotuBalduFailas, BaldaiVisi, m);// Surikiuoti baldai spausdinami į failą. BaldaiVisi - klasių masyvas, m - kiekis, RikiuotuBalduFailas - "RikiuotiBaldai.txt."
				string tekstas = ""; // Sukuriamas stringas, kuriame bus laikomi surikiuoti baldai.
				BalduNuskaitymasIStringa(RikiuotuBalduFailas, tekstas); // RikiuotuBaldų failas - "RikiuotiBaldai.txt", tekstas - stringas, kuria laikomi surikiuoti baldai.
				richTextBox1->Text = ConvertStdToSystemString(tekstas); // Surikiuoti baldai įrašomi į richTextBox1, kad matytų vartotojas.

			}
		else 
			MessageBox::Show("Nera tokio rikiavimo tipo!", "Ispejimas", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);

}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) { //Atliekami veiksmai paspaudus mygtuką "Grįžti".
	this->Hide(); //Uždaromas programos langas.
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) { //Atliekami veiksmai paspaudus mygtuką "Testi".
	Pirkimas ^ PirkimoForma = gcnew Pirkimas(Temp, Miestas, progressBar2->Value); //Sukuriama nauja forma, kuriai perduodamos reikšmės Temp - maksimalus kvadratų skaičius, Miestas - miestas, 
																				  //progressBar2->Value - apartamentų kaina su baldais.
	this->Hide(); 
	PirkimoForma->ShowDialog();
	this->Show(); 
}
};
}
