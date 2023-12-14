#pragma once

namespace moneyexchangeapp {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			InitializeExchangeRates();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label_from;
	private: System::Windows::Forms::Label^ label_to;
	protected:







	private: System::Windows::Forms::Button^ button_convert;
	private: System::Windows::Forms::TextBox^ textBox_amount;




	private: System::Windows::Forms::ComboBox^ comboBox_from;
	private: System::Windows::Forms::ComboBox^ comboBox_to;


	private: System::Windows::Forms::Label^ label_amount;

	private: Dictionary<String^, double>^ exchangeRates;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

	private:
		void InitializeExchangeRates()
		{
			exchangeRates = gcnew Dictionary<String^, double>();
			exchangeRates->Add("USD - US Dollar", 1.00);
			exchangeRates->Add("EUR - Euro", 0.91052873);
			exchangeRates->Add("UAH - Ukrainian Hryvnia", 37.014667);
			exchangeRates->Add("POL - Polish Zloty", 3.9278353);
			exchangeRates->Add("GBP - British Pounds", 0.78434605);
			exchangeRates->Add("JPY - Japanese Yen", 141.93389);
			exchangeRates->Add("CHF - Swiss Francs", 0.86650689);
			exchangeRates->Add("BTC - Bitcoin", 0.0000231319);
			exchangeRates->Add("ETH - Ethereum", 0.0004329773);
			exchangeRates->Add("DOGE - Dogecoin", 10.1079893481);

			comboBox_from->Items->Clear();
			comboBox_to->Items->Clear();

			for each (KeyValuePair<String^, double> kvp in exchangeRates)
			{
				comboBox_from->Items->Add(kvp.Key);
				comboBox_to->Items->Add(kvp.Key);
			}
		}

		String^ FormatNumber(double number)
		{
			// Сначала преобразуем число с максимальным количеством знаков после запятой
			String^ formatted = number.ToString("F8");

			// Удаляем ненужные нули с конца, но оставляем минимум два знака после запятой
			formatted = formatted->TrimEnd('0');
			if (formatted->EndsWith("."))
			{
				formatted += "00"; // Гарантируем минимум два знака после запятой
			}
			else if (formatted[formatted->Length - 2] == '.')
			{
				formatted += "0"; // Гарантируем минимум два знака после запятой
			}

			// Возвращаем обработанное число
			return formatted;
		}




#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label_from = (gcnew System::Windows::Forms::Label());
			this->label_to = (gcnew System::Windows::Forms::Label());
			this->button_convert = (gcnew System::Windows::Forms::Button());
			this->textBox_amount = (gcnew System::Windows::Forms::TextBox());
			this->comboBox_from = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox_to = (gcnew System::Windows::Forms::ComboBox());
			this->label_amount = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label_from
			// 
			this->label_from->AutoSize = true;
			this->label_from->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_from->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(87)));
			this->label_from->Location = System::Drawing::Point(48, 62);
			this->label_from->Name = L"label_from";
			this->label_from->Size = System::Drawing::Size(76, 34);
			this->label_from->TabIndex = 0;
			this->label_from->Text = L"From";
			// 
			// label_to
			// 
			this->label_to->AutoSize = true;
			this->label_to->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_to->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(87)));
			this->label_to->Location = System::Drawing::Point(397, 62);
			this->label_to->Name = L"label_to";
			this->label_to->Size = System::Drawing::Size(42, 34);
			this->label_to->TabIndex = 1;
			this->label_to->Text = L"To";
			// 
			// button_convert
			// 
			this->button_convert->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(113)),
				static_cast<System::Int32>(static_cast<System::Byte>(235)));
			this->button_convert->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_convert->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_convert->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_convert->ForeColor = System::Drawing::Color::Transparent;
			this->button_convert->Location = System::Drawing::Point(597, 285);
			this->button_convert->Name = L"button_convert";
			this->button_convert->Size = System::Drawing::Size(129, 39);
			this->button_convert->TabIndex = 7;
			this->button_convert->Text = L"Convert";
			this->button_convert->UseVisualStyleBackColor = false;
			this->button_convert->Click += gcnew System::EventHandler(this, &MyForm::button_convert_Click);
			// 
			// textBox_amount
			// 
			this->textBox_amount->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 21.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBox_amount->Location = System::Drawing::Point(54, 215);
			this->textBox_amount->Multiline = true;
			this->textBox_amount->Name = L"textBox_amount";
			this->textBox_amount->Size = System::Drawing::Size(278, 40);
			this->textBox_amount->TabIndex = 10;
			// 
			// comboBox_from
			// 
			this->comboBox_from->Cursor = System::Windows::Forms::Cursors::Hand;
			this->comboBox_from->FormattingEnabled = true;
			this->comboBox_from->Location = System::Drawing::Point(54, 99);
			this->comboBox_from->Name = L"comboBox_from";
			this->comboBox_from->Size = System::Drawing::Size(278, 21);
			this->comboBox_from->TabIndex = 11;
			// 
			// comboBox_to
			// 
			this->comboBox_to->Cursor = System::Windows::Forms::Cursors::Hand;
			this->comboBox_to->FormattingEnabled = true;
			this->comboBox_to->Location = System::Drawing::Point(403, 99);
			this->comboBox_to->Name = L"comboBox_to";
			this->comboBox_to->Size = System::Drawing::Size(278, 21);
			this->comboBox_to->TabIndex = 12;
			// 
			// label_amount
			// 
			this->label_amount->AutoSize = true;
			this->label_amount->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_amount->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(87)));
			this->label_amount->Location = System::Drawing::Point(48, 178);
			this->label_amount->Name = L"label_amount";
			this->label_amount->Size = System::Drawing::Size(108, 34);
			this->label_amount->TabIndex = 13;
			this->label_amount->Text = L"Amount";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(87)));
			this->label4->Location = System::Drawing::Point(397, 221);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 34);
			this->label4->TabIndex = 6;
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(738, 336);
			this->Controls->Add(this->label_amount);
			this->Controls->Add(this->comboBox_to);
			this->Controls->Add(this->comboBox_from);
			this->Controls->Add(this->textBox_amount);
			this->Controls->Add(this->button_convert);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label_to);
			this->Controls->Add(this->label_from);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ExChange";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_convert_Click(System::Object^ sender, System::EventArgs^ e) {

		void button_convert_Click(System::Object ^ sender, System::EventArgs ^ e);
		{

			String^ fromCurrency = comboBox_from->SelectedItem->ToString();
			String^ toCurrency = comboBox_to->SelectedItem->ToString();
			double amount;

			try
			{
				amount = Convert::ToDouble(textBox_amount->Text);
			}
			catch (FormatException^)
			{
				MessageBox::Show("Please enter a valid amount.");
				return;
			}

			double fromRate = exchangeRates[fromCurrency];
			double toRate = exchangeRates[toCurrency];
			double convertedAdmount = (amount / fromRate) * toRate;

			label4->Text = convertedAdmount.ToString("N8");
		}
	}
};
}
