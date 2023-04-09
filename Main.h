#pragma once
#include "Renderer.h"
#include "Serialization.h"
#include "Graphic.h"
#include "View.h"

namespace ClassDiagram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace Graphic;

	//Тип нажатой кнопки
	enum ButtonType
	{

		//
		//Кнопки соединений
		//
		Dependency=0,//Зависимость
		Association=1,//Ассоциация
		Aggregation=2,//Агрегация
		Composition=3,//Композиция
		Generalization=4,//Наследование
		Realization=5,//Реализация
		//
		//Кнопки объектов
		//
		Class=6,//Объект Класс
		Interface=7,//Объект Интерфейс
		//
		//Кнопки управления
		//
		Move=8, //Движение
		Remove=9 //Удаление
	};

	/// <summary>
	/// Сводка для Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	private:
		//Свойства и объекты
		Color MainColor = System::Drawing::Color::Transparent;//Основной цвет заднего фона кнопок
		Color SelectedColor = Color::FromArgb(88, 149, 108);
		bool FLAG_MOVE_ENABLE;//Флаг разрешения движения
		bool FLAG_CONNECT_ENABLE;//Флаг разрешения соединения
		bool FLAG_EDIT_ENABLE;//Флаг разрешения редактирования
		PaintObject ^CurrentObject;//Объект диаграммы(Элемент диаграммы или соединение)
		BasicObject ^EditObject;//Элемент диаграммы
		Connector ^CurrentLine;//Соединение
		Space^ space;//Поле рисования
		SerializationData^ file;//Менеджер файлов

	private: System::Windows::Forms::ToolStripButton^ buttonInterface;



	private: System::Windows::Forms::SaveFileDialog^ exportFileDialog;






	private: System::Windows::Forms::ToolStripLabel^ toolStripLabel2;

	private: System::Windows::Forms::ToolStripLabel^ toolStripLabel3;
	private: System::Windows::Forms::ToolStripButton^ ButtonDependency;
	private: System::Windows::Forms::ToolStripButton^ buttonAssotiation;
	private: System::Windows::Forms::ToolStripButton^ buttonAggregation;





	private: System::Windows::Forms::ToolStripButton^ buttonComposition;
	private: System::Windows::Forms::ToolStripButton^ buttonRealization;


	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ файлToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ buttonOpen;
	private: System::Windows::Forms::ToolStripMenuItem^ buttonSave;
	private: System::Windows::Forms::ToolStripMenuItem^ buttonExport;



	private: System::Windows::Forms::ToolStripButton^ buttonGeneralization;









		ButtonType SelectedButton;//Тип нажатой кнопки
		//Методы
		void Main::ChangeData();//Метод изменения данных
		void ResetStyle();//Метод сброса стилей
		void IniControls();//Инициализация компонентов формы
		void UpdatePicture();//Обновление изображения PictureBox
		void ConnectObject(Point current_loc, ButtonType type);









	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	public:
		Main(void);

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:












	private: System::Windows::Forms::ToolStrip^ toolStrip2;
	private: System::Windows::Forms::ToolStripButton^ toolMove;
	private: System::Windows::Forms::ToolStripButton^ toolRemove;














	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel3;
	private: System::Windows::Forms::PictureBox^ pictureBox1;



	private: System::Windows::Forms::ToolStrip^ toolStrip1;








private: System::Windows::Forms::ToolStripButton^ buttonClass;









	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel4;










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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
			this->toolStrip2 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolMove = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolRemove = (gcnew System::Windows::Forms::ToolStripButton());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripLabel2 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->buttonClass = (gcnew System::Windows::Forms::ToolStripButton());
			this->buttonInterface = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripLabel3 = (gcnew System::Windows::Forms::ToolStripLabel());
			this->ButtonDependency = (gcnew System::Windows::Forms::ToolStripButton());
			this->buttonAssotiation = (gcnew System::Windows::Forms::ToolStripButton());
			this->buttonAggregation = (gcnew System::Windows::Forms::ToolStripButton());
			this->buttonComposition = (gcnew System::Windows::Forms::ToolStripButton());
			this->buttonGeneralization = (gcnew System::Windows::Forms::ToolStripButton());
			this->buttonRealization = (gcnew System::Windows::Forms::ToolStripButton());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->buttonOpen = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->buttonSave = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->buttonExport = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->exportFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->toolStrip2->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// toolStrip2
			// 
			this->toolStrip2->AutoSize = false;
			this->toolStrip2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(155)), static_cast<System::Int32>(static_cast<System::Byte>(196)),
				static_cast<System::Int32>(static_cast<System::Byte>(168)));
			this->toolStrip2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->toolStrip2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->toolStrip2->GripStyle = System::Windows::Forms::ToolStripGripStyle::Hidden;
			this->toolStrip2->ImageScalingSize = System::Drawing::Size(30, 35);
			this->toolStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->toolMove, this->toolRemove });
			this->toolStrip2->Location = System::Drawing::Point(0, 30);
			this->toolStrip2->Name = L"toolStrip2";
			this->toolStrip2->Size = System::Drawing::Size(154, 40);
			this->toolStrip2->TabIndex = 1;
			this->toolStrip2->Text = L"toolStrip2";
			this->toolStrip2->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &Main::toolStrip_ItemClicked);
			// 
			// toolMove
			// 
			this->toolMove->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolMove->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolMove.Image")));
			this->toolMove->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolMove->Margin = System::Windows::Forms::Padding(12, 1, 0, 2);
			this->toolMove->Name = L"toolMove";
			this->toolMove->Size = System::Drawing::Size(34, 37);
			this->toolMove->Text = L"toolStripButton6";
			this->toolMove->ToolTipText = L"Курсор";
			this->toolMove->Click += gcnew System::EventHandler(this, &Main::toolMove_Click);
			// 
			// toolRemove
			// 
			this->toolRemove->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->toolRemove->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolRemove->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolRemove.Image")));
			this->toolRemove->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolRemove->Margin = System::Windows::Forms::Padding(0, 1, 12, 2);
			this->toolRemove->Name = L"toolRemove";
			this->toolRemove->Size = System::Drawing::Size(34, 37);
			this->toolRemove->Text = L"Удалить объект";
			this->toolRemove->ToolTipText = L"Удалить";
			this->toolRemove->Click += gcnew System::EventHandler(this, &Main::toolRemove_Click);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->BackColor = System::Drawing::Color::Transparent;
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				160)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel3, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel4, 1, 1);
			this->tableLayoutPanel2->Controls->Add(this->menuStrip1, 0, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel2->Size = System::Drawing::Size(843, 818);
			this->tableLayoutPanel2->TabIndex = 9;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(155)),
				static_cast<System::Int32>(static_cast<System::Byte>(196)), static_cast<System::Int32>(static_cast<System::Byte>(168)));
			this->tableLayoutPanel3->ColumnCount = 1;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel3->Controls->Add(this->toolStrip1, 0, 2);
			this->tableLayoutPanel3->Controls->Add(this->toolStrip2, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->panel1, 0, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 33);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 3;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel3->Size = System::Drawing::Size(154, 782);
			this->tableLayoutPanel3->TabIndex = 10;
			// 
			// toolStrip1
			// 
			this->toolStrip1->AutoSize = false;
			this->toolStrip1->BackColor = System::Drawing::Color::Transparent;
			this->toolStrip1->CanOverflow = false;
			this->toolStrip1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->toolStrip1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(150, 80);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(10) {
				this->toolStripLabel2,
					this->buttonClass, this->buttonInterface, this->toolStripLabel3, this->ButtonDependency, this->buttonAssotiation, this->buttonAggregation,
					this->buttonComposition, this->buttonGeneralization, this->buttonRealization
			});
			this->toolStrip1->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::Table;
			this->toolStrip1->Location = System::Drawing::Point(0, 70);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Padding = System::Windows::Forms::Padding(0, 10, 0, 0);
			this->toolStrip1->Size = System::Drawing::Size(154, 712);
			this->toolStrip1->TabIndex = 0;
			this->toolStrip1->Text = L"toolStrip1";
			this->toolStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &Main::toolStrip_ItemClicked);
			// 
			// toolStripLabel2
			// 
			this->toolStripLabel2->Name = L"toolStripLabel2";
			this->toolStripLabel2->Size = System::Drawing::Size(53, 21);
			this->toolStripLabel2->Text = L"Блоки";
			// 
			// buttonClass
			// 
			this->buttonClass->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->buttonClass->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonClass.Image")));
			this->buttonClass->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->buttonClass->Name = L"buttonClass";
			this->buttonClass->Size = System::Drawing::Size(154, 84);
			this->buttonClass->Text = L"Процесс";
			this->buttonClass->ToolTipText = L"Класс";
			this->buttonClass->Click += gcnew System::EventHandler(this, &Main::buttonClass_Click);
			// 
			// buttonInterface
			// 
			this->buttonInterface->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->buttonInterface->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonInterface.Image")));
			this->buttonInterface->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->buttonInterface->Name = L"buttonInterface";
			this->buttonInterface->Size = System::Drawing::Size(154, 84);
			this->buttonInterface->Text = L"toolStripButton1";
			this->buttonInterface->ToolTipText = L"Интерфейс";
			this->buttonInterface->Click += gcnew System::EventHandler(this, &Main::buttonInterface_Click);
			// 
			// toolStripLabel3
			// 
			this->toolStripLabel3->Name = L"toolStripLabel3";
			this->toolStripLabel3->Size = System::Drawing::Size(52, 21);
			this->toolStripLabel3->Text = L"Связи";
			// 
			// ButtonDependency
			// 
			this->ButtonDependency->AutoSize = false;
			this->ButtonDependency->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->ButtonDependency->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ButtonDependency.Image")));
			this->ButtonDependency->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->ButtonDependency->Name = L"ButtonDependency";
			this->ButtonDependency->Size = System::Drawing::Size(154, 60);
			this->ButtonDependency->Text = L"toolStripButton2";
			this->ButtonDependency->ToolTipText = L"Зависимость";
			this->ButtonDependency->Click += gcnew System::EventHandler(this, &Main::ButtonDependency_Click);
			// 
			// buttonAssotiation
			// 
			this->buttonAssotiation->AutoSize = false;
			this->buttonAssotiation->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->buttonAssotiation->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonAssotiation.Image")));
			this->buttonAssotiation->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->buttonAssotiation->Name = L"buttonAssotiation";
			this->buttonAssotiation->Size = System::Drawing::Size(154, 60);
			this->buttonAssotiation->Text = L"toolStripButton3";
			this->buttonAssotiation->ToolTipText = L"Ассоциация";
			this->buttonAssotiation->Click += gcnew System::EventHandler(this, &Main::buttonAssotiation_Click);
			// 
			// buttonAggregation
			// 
			this->buttonAggregation->AutoSize = false;
			this->buttonAggregation->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->buttonAggregation->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonAggregation.Image")));
			this->buttonAggregation->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->buttonAggregation->Name = L"buttonAggregation";
			this->buttonAggregation->Size = System::Drawing::Size(154, 60);
			this->buttonAggregation->Text = L"toolStripButton4";
			this->buttonAggregation->ToolTipText = L"Агрегация";
			this->buttonAggregation->Click += gcnew System::EventHandler(this, &Main::buttonAggregation_Click);
			// 
			// buttonComposition
			// 
			this->buttonComposition->AutoSize = false;
			this->buttonComposition->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->buttonComposition->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonComposition.Image")));
			this->buttonComposition->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->buttonComposition->Name = L"buttonComposition";
			this->buttonComposition->Size = System::Drawing::Size(154, 60);
			this->buttonComposition->Text = L"toolStripButton5";
			this->buttonComposition->ToolTipText = L"Композиция";
			this->buttonComposition->Click += gcnew System::EventHandler(this, &Main::buttonComposition_Click);
			// 
			// buttonGeneralization
			// 
			this->buttonGeneralization->AutoSize = false;
			this->buttonGeneralization->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->buttonGeneralization->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonGeneralization.Image")));
			this->buttonGeneralization->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->buttonGeneralization->Name = L"buttonGeneralization";
			this->buttonGeneralization->Size = System::Drawing::Size(154, 60);
			this->buttonGeneralization->ToolTipText = L"Наследование";
			this->buttonGeneralization->Click += gcnew System::EventHandler(this, &Main::buttonGeneralization_Click);
			// 
			// buttonRealization
			// 
			this->buttonRealization->AutoSize = false;
			this->buttonRealization->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->buttonRealization->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonRealization.Image")));
			this->buttonRealization->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->buttonRealization->Name = L"buttonRealization";
			this->buttonRealization->Size = System::Drawing::Size(154, 60);
			this->buttonRealization->Text = L"toolStripButton6";
			this->buttonRealization->ToolTipText = L"Реализация";
			this->buttonRealization->Click += gcnew System::EventHandler(this, &Main::buttonRealization_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(154, 30);
			this->panel1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Margin = System::Windows::Forms::Padding(0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(154, 30);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Инструменты";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 1;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel4->Controls->Add(this->pictureBox1, 0, 0);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(163, 33);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel4->Size = System::Drawing::Size(677, 782);
			this->tableLayoutPanel4->TabIndex = 11;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::Control;
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Location = System::Drawing::Point(3, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(671, 776);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->SizeChanged += gcnew System::EventHandler(this, &Main::pictureBox1_SizeChanged);
			this->pictureBox1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Main::pictureBox1_MouseDoubleClick);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Main::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Main::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Main::pictureBox1_MouseUp);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(88)), static_cast<System::Int32>(static_cast<System::Byte>(149)),
				static_cast<System::Int32>(static_cast<System::Byte>(108)));
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->файлToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(160, 29);
			this->menuStrip1->TabIndex = 12;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// файлToolStripMenuItem
			// 
			this->файлToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(88)),
				static_cast<System::Int32>(static_cast<System::Byte>(149)), static_cast<System::Int32>(static_cast<System::Byte>(108)));
			this->файлToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->buttonOpen,
					this->buttonSave, this->buttonExport
			});
			this->файлToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(155)),
				static_cast<System::Int32>(static_cast<System::Byte>(196)), static_cast<System::Int32>(static_cast<System::Byte>(168)));
			this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
			this->файлToolStripMenuItem->Size = System::Drawing::Size(61, 25);
			this->файлToolStripMenuItem->Text = L"Файл";
			this->файлToolStripMenuItem->DropDownItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &Main::toolStrip_ItemClicked);
			// 
			// buttonOpen
			// 
			this->buttonOpen->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(88)), static_cast<System::Int32>(static_cast<System::Byte>(149)),
				static_cast<System::Int32>(static_cast<System::Byte>(108)));
			this->buttonOpen->Name = L"buttonOpen";
			this->buttonOpen->Size = System::Drawing::Size(204, 26);
			this->buttonOpen->Text = L"Открыть";
			this->buttonOpen->Click += gcnew System::EventHandler(this, &Main::buttonOpen_Click);
			// 
			// buttonSave
			// 
			this->buttonSave->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(88)), static_cast<System::Int32>(static_cast<System::Byte>(149)),
				static_cast<System::Int32>(static_cast<System::Byte>(108)));
			this->buttonSave->Name = L"buttonSave";
			this->buttonSave->Size = System::Drawing::Size(204, 26);
			this->buttonSave->Text = L"Сохранить";
			this->buttonSave->Click += gcnew System::EventHandler(this, &Main::buttonSave_Click);
			// 
			// buttonExport
			// 
			this->buttonExport->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(88)), static_cast<System::Int32>(static_cast<System::Byte>(149)),
				static_cast<System::Int32>(static_cast<System::Byte>(108)));
			this->buttonExport->Name = L"buttonExport";
			this->buttonExport->Size = System::Drawing::Size(204, 26);
			this->buttonExport->Text = L"Экспортировать";
			this->buttonExport->Click += gcnew System::EventHandler(this, &Main::buttonExport_Click);
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->FileName = L"Классовая диаграмма";
			// 
			// exportFileDialog
			// 
			this->exportFileDialog->FileName = L"Классовая диаграмма";
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(88)), static_cast<System::Int32>(static_cast<System::Byte>(149)),
				static_cast<System::Int32>(static_cast<System::Byte>(108)));
			this->ClientSize = System::Drawing::Size(843, 818);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"Main";
			this->Text = L"Редактор классовой диаграммы";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->toolStrip2->ResumeLayout(false);
			this->toolStrip2->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void toolMove_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void toolRemove_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void toolClear_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonSave_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonOpen_Click(System::Object^ sender, System::EventArgs^ e);


private: System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

private: System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void pictureBox1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void pictureBox1_SizeChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void pictureBox1_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void toolStrip_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e);
private: System::Void buttonExport_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonClass_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonInterface_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ButtonDependency_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonAssotiation_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void buttonAggregation_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonComposition_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonRealization_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonGeneralization_Click(System::Object^ sender, System::EventArgs^ e);
};
}
