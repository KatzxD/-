#pragma once
#include "Graphic.h"
#include "Data.h"

namespace ClassDiagram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Graphic;

	/// <summary>
	/// Сводка для View
	/// </summary>
	public ref class View : public System::Windows::Forms::Form
	{
		array<String^> ^mods;
		DataBlock^ data;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ gridAttr_columnNumber;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ gridAttr_columnMod;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ gridAttr_columnName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ gridAttr_columnType;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ gridMethods_columnNumber;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ gridMethods_columnMod;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ gridMethods_columnName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ gridMethods_columnType;
		   Graphic::TypeObject type;
	public:
		View(DataBlock^ data, Graphic::TypeObject type);
		void FillData();
		void SetDefaultData();
		AccessModifier StringToEnum(String^ str);
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~View()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ tabControl;
	protected:

	private: System::Windows::Forms::TabPage^ tabPageAttr;
	private: System::Windows::Forms::TabPage^ tabPageMethods;
	private: System::Windows::Forms::TextBox^ textBoxTitle;
	protected:



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ buttonAccept;

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::DataGridView^ gridAttr;
	private: System::Windows::Forms::DataGridView^ gridMethods;
















	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl = (gcnew System::Windows::Forms::TabControl());
			this->tabPageAttr = (gcnew System::Windows::Forms::TabPage());
			this->gridAttr = (gcnew System::Windows::Forms::DataGridView());
			this->gridAttr_columnNumber = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->gridAttr_columnMod = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->gridAttr_columnName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->gridAttr_columnType = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPageMethods = (gcnew System::Windows::Forms::TabPage());
			this->gridMethods = (gcnew System::Windows::Forms::DataGridView());
			this->gridMethods_columnNumber = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->gridMethods_columnMod = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->gridMethods_columnName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->gridMethods_columnType = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->textBoxTitle = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonAccept = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->tabControl->SuspendLayout();
			this->tabPageAttr->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridAttr))->BeginInit();
			this->tabPageMethods->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridMethods))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl
			// 
			this->tabControl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl->Controls->Add(this->tabPageAttr);
			this->tabControl->Controls->Add(this->tabPageMethods);
			this->tabControl->Location = System::Drawing::Point(12, 60);
			this->tabControl->Name = L"tabControl";
			this->tabControl->SelectedIndex = 0;
			this->tabControl->Size = System::Drawing::Size(765, 426);
			this->tabControl->TabIndex = 0;
			// 
			// tabPageAttr
			// 
			this->tabPageAttr->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(155)), static_cast<System::Int32>(static_cast<System::Byte>(196)),
				static_cast<System::Int32>(static_cast<System::Byte>(168)));
			this->tabPageAttr->Controls->Add(this->gridAttr);
			this->tabPageAttr->Location = System::Drawing::Point(4, 29);
			this->tabPageAttr->Name = L"tabPageAttr";
			this->tabPageAttr->Padding = System::Windows::Forms::Padding(3);
			this->tabPageAttr->Size = System::Drawing::Size(757, 393);
			this->tabPageAttr->TabIndex = 0;
			this->tabPageAttr->Text = L"Атрибуты";
			// 
			// gridAttr
			// 
			this->gridAttr->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(155)), static_cast<System::Int32>(static_cast<System::Byte>(196)),
				static_cast<System::Int32>(static_cast<System::Byte>(168)));
			this->gridAttr->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridAttr->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->gridAttr_columnNumber,
					this->gridAttr_columnMod, this->gridAttr_columnName, this->gridAttr_columnType
			});
			this->gridAttr->Dock = System::Windows::Forms::DockStyle::Fill;
			this->gridAttr->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
			this->gridAttr->Location = System::Drawing::Point(3, 3);
			this->gridAttr->Name = L"gridAttr";
			this->gridAttr->Size = System::Drawing::Size(751, 387);
			this->gridAttr->TabIndex = 0;
			this->gridAttr->RowsAdded += gcnew System::Windows::Forms::DataGridViewRowsAddedEventHandler(this, &View::gridAttr_RowsAdded);
			// 
			// gridAttr_columnNumber
			// 
			this->gridAttr_columnNumber->HeaderText = L"Номер";
			this->gridAttr_columnNumber->MinimumWidth = 70;
			this->gridAttr_columnNumber->Name = L"gridAttr_columnNumber";
			this->gridAttr_columnNumber->ReadOnly = true;
			this->gridAttr_columnNumber->Width = 70;
			// 
			// gridAttr_columnMod
			// 
			this->gridAttr_columnMod->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->gridAttr_columnMod->HeaderText = L"Модификатор доступа";
			this->gridAttr_columnMod->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Закрытый", L"Публичный", L"Защищенный" });
			this->gridAttr_columnMod->Name = L"gridAttr_columnMod";
			this->gridAttr_columnMod->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->gridAttr_columnMod->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->gridAttr_columnMod->Width = 191;
			// 
			// gridAttr_columnName
			// 
			this->gridAttr_columnName->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->gridAttr_columnName->HeaderText = L"Название";
			this->gridAttr_columnName->MinimumWidth = 300;
			this->gridAttr_columnName->Name = L"gridAttr_columnName";
			this->gridAttr_columnName->Width = 300;
			// 
			// gridAttr_columnType
			// 
			this->gridAttr_columnType->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->gridAttr_columnType->HeaderText = L"Тип данных";
			this->gridAttr_columnType->Name = L"gridAttr_columnType";
			// 
			// tabPageMethods
			// 
			this->tabPageMethods->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(155)), static_cast<System::Int32>(static_cast<System::Byte>(196)),
				static_cast<System::Int32>(static_cast<System::Byte>(168)));
			this->tabPageMethods->Controls->Add(this->gridMethods);
			this->tabPageMethods->Location = System::Drawing::Point(4, 29);
			this->tabPageMethods->Name = L"tabPageMethods";
			this->tabPageMethods->Padding = System::Windows::Forms::Padding(3);
			this->tabPageMethods->Size = System::Drawing::Size(757, 393);
			this->tabPageMethods->TabIndex = 1;
			this->tabPageMethods->Text = L"Методы";
			// 
			// gridMethods
			// 
			this->gridMethods->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridMethods->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->gridMethods_columnNumber,
					this->gridMethods_columnMod, this->gridMethods_columnName, this->gridMethods_columnType
			});
			this->gridMethods->Dock = System::Windows::Forms::DockStyle::Fill;
			this->gridMethods->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
			this->gridMethods->Location = System::Drawing::Point(3, 3);
			this->gridMethods->Name = L"gridMethods";
			this->gridMethods->Size = System::Drawing::Size(751, 387);
			this->gridMethods->TabIndex = 1;
			this->gridMethods->UserAddedRow += gcnew System::Windows::Forms::DataGridViewRowEventHandler(this, &View::gridMethods_UserAddedRow);
			// 
			// gridMethods_columnNumber
			// 
			this->gridMethods_columnNumber->HeaderText = L"Номер";
			this->gridMethods_columnNumber->MinimumWidth = 70;
			this->gridMethods_columnNumber->Name = L"gridMethods_columnNumber";
			this->gridMethods_columnNumber->ReadOnly = true;
			this->gridMethods_columnNumber->Width = 70;
			// 
			// gridMethods_columnMod
			// 
			this->gridMethods_columnMod->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->gridMethods_columnMod->HeaderText = L"Модификатор доступа";
			this->gridMethods_columnMod->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Публичный", L"Закрытый", L"Защищенный" });
			this->gridMethods_columnMod->Name = L"gridMethods_columnMod";
			this->gridMethods_columnMod->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->gridMethods_columnMod->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->gridMethods_columnMod->Width = 191;
			// 
			// gridMethods_columnName
			// 
			this->gridMethods_columnName->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->gridMethods_columnName->HeaderText = L"Название";
			this->gridMethods_columnName->MinimumWidth = 300;
			this->gridMethods_columnName->Name = L"gridMethods_columnName";
			this->gridMethods_columnName->Width = 300;
			// 
			// gridMethods_columnType
			// 
			this->gridMethods_columnType->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->gridMethods_columnType->HeaderText = L"Тип данных";
			this->gridMethods_columnType->Name = L"gridMethods_columnType";
			// 
			// textBoxTitle
			// 
			this->textBoxTitle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(155)), static_cast<System::Int32>(static_cast<System::Byte>(196)),
				static_cast<System::Int32>(static_cast<System::Byte>(168)));
			this->textBoxTitle->Location = System::Drawing::Point(98, 8);
			this->textBoxTitle->Name = L"textBoxTitle";
			this->textBoxTitle->Size = System::Drawing::Size(359, 26);
			this->textBoxTitle->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 11);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(83, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Название";
			// 
			// buttonAccept
			// 
			this->buttonAccept->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonAccept->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(91)));
			this->buttonAccept->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->buttonAccept->Location = System::Drawing::Point(625, 492);
			this->buttonAccept->Name = L"buttonAccept";
			this->buttonAccept->Size = System::Drawing::Size(152, 39);
			this->buttonAccept->TabIndex = 3;
			this->buttonAccept->Text = L"ОК";
			this->buttonAccept->UseVisualStyleBackColor = false;
			this->buttonAccept->Click += gcnew System::EventHandler(this, &View::buttonAccept_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->textBoxTitle);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(471, 42);
			this->panel1->TabIndex = 4;
			// 
			// View
			// 
			this->AcceptButton = this->buttonAccept;
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(88)), static_cast<System::Int32>(static_cast<System::Byte>(149)),
				static_cast<System::Int32>(static_cast<System::Byte>(108)));
			this->ClientSize = System::Drawing::Size(789, 543);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->buttonAccept);
			this->Controls->Add(this->tabControl);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"View";
			this->Text = L"View";
			this->tabControl->ResumeLayout(false);
			this->tabPageAttr->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridAttr))->EndInit();
			this->tabPageMethods->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridMethods))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void buttonAccept_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void gridAttr_RowsAdded(System::Object^ sender, System::Windows::Forms::DataGridViewRowsAddedEventArgs^ e);
private: System::Void gridMethods_UserAddedRow(System::Object^ sender, System::Windows::Forms::DataGridViewRowEventArgs^ e);
};
}
