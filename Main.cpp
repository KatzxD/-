#include "Main.h"


namespace ClassDiagram {

	//������������� ����������� �����
	void Main::IniControls()
	{
		tableLayoutPanel2->BorderStyle = BorderStyle::FixedSingle;
		tableLayoutPanel3->BorderStyle = BorderStyle::FixedSingle;
		tableLayoutPanel4->BorderStyle = BorderStyle::FixedSingle;
		toolStrip1->Renderer = gcnew Renderer(SelectedColor);
		toolStrip2->Renderer = gcnew Renderer(SelectedColor);
		//toolStrip3->Renderer = gcnew Renderer(SelectedColor);
		openFileDialog1->Filter = "(*.xml)|*.xml";
		saveFileDialog1->Filter = "(*.xml)|*.xml";
		exportFileDialog->Filter = "(*.jpg)|*.jpg";
		//toolMove->Select();
		SelectedButton= ButtonType::Move;
		toolMove_Click(this, nullptr);
	}
	//���������� �����������
	void Main::UpdatePicture()
	{
		space->Paint();
		pictureBox1->Refresh();

	}
	//����������� �������� �������������� ������
	void Main::ConnectObject(Point current_loc, ButtonType type)
	{
		PaintObject^ f = space->GetBlock(current_loc);
		if (f != nullptr)
		{
			if (!FLAG_CONNECT_ENABLE)
			{
				CurrentLine = gcnew ClassDiagram::Connector(f, current_loc, (TypeConnection)type);
			}
			else
			{
				CurrentLine->ConnectFigure(f);

			}
			FLAG_CONNECT_ENABLE = space->AddConnection(CurrentLine);
		}
	}

	Main::Main(void)
	{
		InitializeComponent();
		IniControls();
		space = gcnew Space(pictureBox1->Size);
		pictureBox1->Image = space->image;
	}
	//����� ������
	void Main::ResetStyle()
	{
		toolMove->BackColor = MainColor;
		toolRemove->BackColor = MainColor;
		buttonClass->BackColor = MainColor;
		buttonInterface->BackColor = MainColor;
		ButtonDependency->BackColor = MainColor;
		buttonAssotiation->BackColor = MainColor;
		buttonAggregation->BackColor = MainColor;
		buttonComposition->BackColor = MainColor;
		buttonGeneralization->BackColor = MainColor;
		buttonRealization->BackColor = MainColor;
	}
	//��������� ������� �� �������� ���������
	void Main::ChangeData()
	{
		if (EditObject != nullptr && !FLAG_CONNECT_ENABLE)
		{
			DataBlock^ data = ((Block^)EditObject)->Data;
			TypeObject type = ((Block^)EditObject)->BlockType;
			ClassDiagram::View^ view = gcnew ClassDiagram::View(data, type);
			view->ShowDialog();
			((Block^)EditObject)->UpdateSize();
			FLAG_EDIT_ENABLE = false;
		}
	}
	
	
	System::Void Main::toolStrip_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e)
	{

		if (CurrentLine != nullptr && FLAG_CONNECT_ENABLE)
		{
			space->RemoveConnection(CurrentLine);
			FLAG_CONNECT_ENABLE = false;
			UpdatePicture();
		}

	}
	System::Void Main::buttonExport_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (exportFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			try
			{
				String^ url = exportFileDialog->FileName;
				pictureBox1->Image->Save(url);
				MessageBox::Show("����������� ���������", "�����������", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			catch (...)
			{
				MessageBox::Show("������ ��� ���������� �����", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
	System::Void Main::buttonClass_Click(System::Object^ sender, System::EventArgs^ e)
	{
		SelectedButton = ButtonType::Class;
		ResetStyle();
		buttonClass->BackColor = SelectedColor;
	}
	System::Void Main::buttonInterface_Click(System::Object^ sender, System::EventArgs^ e)
	{
		SelectedButton = ButtonType::Interface;
		ResetStyle();
		buttonInterface->BackColor = SelectedColor;
	}
	System::Void Main::ButtonDependency_Click(System::Object^ sender, System::EventArgs^ e)
	{
		SelectedButton = ButtonType::Dependency;
		ResetStyle();
		ButtonDependency->BackColor = SelectedColor;
	}
	System::Void Main::buttonAssotiation_Click(System::Object^ sender, System::EventArgs^ e)
	{
		SelectedButton = ButtonType::Association;
		ResetStyle();
		buttonAssotiation->BackColor = SelectedColor;
	}
	System::Void Main::buttonAggregation_Click(System::Object^ sender, System::EventArgs^ e)
	{
		SelectedButton = ButtonType::Aggregation;
		ResetStyle();
		buttonAggregation->BackColor = SelectedColor;
	}
	System::Void Main::buttonComposition_Click(System::Object^ sender, System::EventArgs^ e)
	{
		SelectedButton = ButtonType::Composition;
		ResetStyle();
		buttonComposition->BackColor = SelectedColor;
	}
	System::Void Main::buttonRealization_Click(System::Object^ sender, System::EventArgs^ e)
	{
		SelectedButton = ButtonType::Realization;
		ResetStyle();
		buttonRealization->BackColor = SelectedColor;
	}
	System::Void Main::buttonGeneralization_Click(System::Object^ sender, System::EventArgs^ e)
	{
		SelectedButton = ButtonType::Generalization;
		ResetStyle();
		buttonGeneralization->BackColor = SelectedColor;
	}
	//������ ������ �������� �����������
	System::Void Main::toolMove_Click(System::Object^ sender, System::EventArgs^ e)
	{
		SelectedButton = ButtonType::Move;
		ResetStyle();
		toolMove->BackColor = SelectedColor;
	}
	//������ ������ �������� ��������
	System::Void Main::toolRemove_Click(System::Object^ sender, System::EventArgs^ e)
	{
		SelectedButton = ButtonType::Remove;
		ResetStyle();
		toolRemove->BackColor = SelectedColor;
	}
	//������ ������� ����
	System::Void Main::toolClear_Click(System::Object^ sender, System::EventArgs^ e)
	{
		space->Clear();
		UpdatePicture();
	}
	//���������� ������
	System::Void Main::buttonSave_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			try
			{
				String^ url = saveFileDialog1->FileName;
				file->Save(space, url);
				MessageBox::Show("������ ���������", "�����������", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			catch (...)
			{
				MessageBox::Show("������ ��� ���������� �����", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
	//�������� ������
	System::Void Main::buttonOpen_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			try
			{
				String^ url = openFileDialog1->FileName;
				Space^ new_area = file->Load(url);
				if (new_area != nullptr)
				{
					space = new_area;
					UpdatePicture();
				}
			}
			catch (...)
			{
				MessageBox::Show("������ ��� �������� �����", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
	//��������� ������� ������� ����� ������ ����
	System::Void Main::pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if(e->Button == System::Windows::Forms::MouseButtons::Left && SelectedButton == ClassDiagram::Move && !FLAG_EDIT_ENABLE)
		{
			CurrentObject = space->GetBlock(e->Location);
			if (CurrentObject != nullptr) 
			{ 
				FLAG_MOVE_ENABLE = true; 
			}
		}
	}
	//��������� ������� ��������
	System::Void Main::pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		//�������� �����
		if (CurrentObject != nullptr && FLAG_MOVE_ENABLE)
		{
			CurrentObject->Location = e->Location;
			UpdatePicture();
		}
		//�������� ����� ���������� �����
		if (CurrentLine != nullptr && FLAG_CONNECT_ENABLE)
		{
			CurrentLine->FlowPoint = e->Location;
			UpdatePicture();
		}
	}
	//��������� ������� ������� �������
	System::Void Main::pictureBox1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			if (FLAG_EDIT_ENABLE)
			{
				BasicObject^ base = space->GetObject(e->Location);
				if (base == nullptr || base != EditObject)
				{
					ChangeData();
				}
			}
			bool multiselect = false;
			if (System::Windows::Input::Keyboard::IsKeyDown(System::Windows::Input::Key::LeftCtrl))
				multiselect = true;
			
			switch (SelectedButton)
			{
			case ButtonType::Remove://��������
			{
				space->RemoveBlock(e->Location);
				break;
			}
			default:
			{
				//���������� ��������
				if (SelectedButton == ButtonType::Class || SelectedButton == ButtonType::Interface)
				{
					space->AddObject(e->Location, (TypeObject)SelectedButton);
					if (!multiselect)
						toolMove_Click(sender, e);
				}
				//���������� ������
				if (SelectedButton >= ButtonType::Dependency && SelectedButton <= ButtonType::Realization)
				{
					ConnectObject(e->Location, SelectedButton);
					if (!multiselect && !FLAG_CONNECT_ENABLE)
						toolMove_Click(sender, e);
				}
			}
			}
			FLAG_MOVE_ENABLE = false;
			
			UpdatePicture();
		}
		//������ �������������  ����� � �������� ���������
		else if (e->Button == System::Windows::Forms::MouseButtons::Right)
		{
			if (CurrentLine != nullptr && FLAG_CONNECT_ENABLE)
			{
				space->RemoveConnection(CurrentLine);
				FLAG_CONNECT_ENABLE = false;
				UpdatePicture();
			}
		}
		
	}
	//�������, �������������� �������������� ��������
	System::Void  Main::pictureBox1_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if (e->Button == System::Windows::Forms::MouseButtons::Left &&
			SelectedButton == ButtonType::Move)
		{
			//�������������� �������� ������� ���������
			EditObject = space->GetObject(e->Location);
			if (EditObject != nullptr)
			{
				ChangeData();
			}
		}
	}

	//��������� ������� ��������� ������� ������
	System::Void Main::pictureBox1_SizeChanged(System::Object^ sender, System::EventArgs^ e)
	{
		pictureBox1->Image = space->Resize(pictureBox1->Size);
		UpdatePicture();
	}



}

