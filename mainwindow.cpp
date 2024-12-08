#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "user.h"
#include "conUserWin.h"
#include "encryption.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    user_mode = 0;

    ui->PAPASHA_GOSLING->setStyleSheet("QLabel {color: #632109; font-size: 18px; font-family: \"Segoe Print\"; font-weight: bold}");
    ui->PAPASHA_GOSLING->setAlignment(Qt::AlignRight);

    ui->MusiChoose->setCurrentIndex(0);
    ui->adminPanel->setCurrentIndex(0);
    users = readUsers();


    //////////////////
    /// LOGIN_PAGE ///
    //////////////////

    MainWindow::setStyleSheet("QMainWindow { background-color: #632109}");

    ui->logIn_frame_1->setStyleSheet("QFrame { background-color: #B88542; border: 4px solid #632109}");

    ui->logIn_frame_2->setStyleSheet("QFrame { background-color: #B88542;");

    ui->MusiChoose->setStyleSheet("QStackedWidget { background-color: #B88542; };");

    ui->nameApp->setStyleSheet("color: #632109; font-size: 64px; font-family: \"Segoe Print\"; font-weight: bold");

    ui->loginLabel->setStyleSheet("color: #632109; font-size: 20px; font-family: \"Segoe Print\"; font-weight: bold;");
    ui->passLabel->setStyleSheet("color: #632109; font-size: 20px; font-family: \"Segoe Print\"; font-weight: bold");

    ui->passEdit->setStyleSheet("QLineEdit {font-size: 18px; font-family: \"Segoe Print\"; color: #632109; font-weight: bold; background-color: #DCB66F; border: 1px solid #632109;"
                                "min-height: 25px; max-height: 25px;}");
    ui->loginEdit->setStyleSheet("QLineEdit {font-size: 18px; font-family: \"Segoe Print\"; color: #632109; font-weight: bold; background-color: #DCB66F; border: 1px solid #632109;"
                                 "min-height: 25px; max-height: 25px;}");

    ui->LogIn_button->setStyleSheet("QPushButton {font-size: 18px; font-family: \"Segoe Print\"; color: #632109; font-weight: bold; background-color: #DCB66F; border: 1px solid #632109; "
                                    "min-width: 80px; max-width: 80px; min-height: 40px; max-height: 40px;}");
    ui->SignUp->setStyleSheet("QPushButton {font-size: 18px; font-family: \"Segoe Print\"; color: #632109; font-weight: bold; background-color: #DCB66F; border: 1px solid #632109;"
                              "min-width: 80px; max-width: 80px; min-height: 40px; max-height: 40px;}");

    ui->visiblePass_checkbox->setStyleSheet("QCheckBox {color: #632109; font-weight: bold; font-size: 16px; font-family: \"Segoe Print\";}"
                                   " QCheckBox::indicator {background-color: #DCB66F; border: 1px solid #632109; }"
                                   "QCheckBox::indicator:checked {"
                                   "background-color: #DCB66F; border: 2px solid #632109;"
                                    "image: url(../../img/noteForCheckBox.png);"
                             "width: 14px; height: 14px;}");




    QPixmap pixmap("../../img/img_login.png");

    ui->img_login->setPixmap(pixmap);
    ui->img_login->setPixmap(pixmap.scaled(ui->img_login->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    ui->passEdit->setEchoMode(QLineEdit::Password);

    pixmap.load("../../img/music.png");



    User user;
    user.setLoginPass("1","1",0);

    std::string line;
    std::ifstream file;





    ///////////////////
    //// MAIN_PAGE ////
    ///////////////////


    ui->nameApp_2->setStyleSheet("color: #632109; font-size: 48px; font-family: \"Segoe Print\"; font-weight: bold");

    ui->userName->setStyleSheet("QLabel {color: #632109; font-size: 24px; font-family: \"Segoe Print\"; font-weight: bold;}"); ui->userName->setAlignment(Qt::AlignRight);

    ui->backToLogIn_button->setStyleSheet("QPushButton {font-size: 18px; font-family: \"Segoe Print\"; color: #632109; font-weight: bold; background-color: #DCB66F; border: 2px solid #632109; "
                                          "min-width: 40px; max-width: 40px; min-height: 20px; max-height: 20px;}");

    ui->backToUsIn1_pushButton->setStyleSheet("QPushButton {font-size: 18px; font-family: \"Segoe Print\"; color: #632109; font-weight: bold; background-color: #DCB66F; border: 2px solid #632109; "
                                          "min-width: 40px; max-width: 40px; min-height: 20px; max-height: 20px;}");

    ui->backToUsIn2_pushButton->setStyleSheet("QPushButton {font-size: 18px; font-family: \"Segoe Print\"; color: #632109; font-weight: bold; background-color: #DCB66F; border: 2px solid #632109; "
                                          "min-width: 40px; max-width: 40px; min-height: 20px; max-height: 20px;}");

    ui->music_frame->setStyleSheet("QLabel {color: #632109; font-size: 16px; font-weight: bold; font-family: \"Segoe Print\"; spacing: 5px} QCheckBox {color: #632109; font-weight: bold; font-size: 16px; font-family: \"Segoe Print\";}"
                                   " QCheckBox::indicator {background-color: #DCB66F; border: 1px solid #632109; }"
                                   "QCheckBox::indicator:checked {"
                                   "background-color: #DCB66F; border: 2px solid #632109;"
                                    "image: url(../../img/noteForCheckBox.png);"
                                    "width: 14px; height: 14px;}"
                                   "QLineEdit {font-size: 16px; font-weight: bold; font-family: \"Segoe Print\"; color: #632109; background-color: #DCB66F; border: 1px solid #632109;"
                         "min-height: 20px; max-height: 20px; min-width: 70px; max-width: 70px;}"
                                   "QPushButton {font-size: 18px; font-family: \"Segoe Print\"; color: #632109; font-weight: bold; background-color: #DCB66F; border: 1px solid #632109; "
                                   "min-width: 144px; max-width: 144px; min-height: 25px; max-height: 25px;}"                                   );
    ui->musicList_scrollArea->setStyleSheet("QScrollArea {border: 2px solid #632109;} QWidget {background-color:#CAA153; color: #632109; font-size: 18px; font-family: \"Segoe Print\"; font-weight: bold;}"/*QLabel {border: 2px solid #632109; background-color: #DCB66F}"*/ );

    ui->adminPanel->setStyleSheet("QPushButton {font-size: 14px; font-family: \"Segoe Print\"; color: #632109; font-weight: bold; background-color: #DCB66F; border: 2px solid #632109; "
                                  "min-width: 64px; max-width: 144px; min-height: 20px; max-height: 20px;}");
    ui->ok_pushButton->setStyleSheet("QPushButton {max-width: 26px; min-width: 26px}");
    ui->backToUs1_pushButton->setStyleSheet("QPushButton {font-size: 18px; font-family: \"Segoe Print\"; color: #632109; font-weight: bold; background-color: #DCB66F; border: 2px solid #632109; "
                                            "min-width: 40px; max-width: 40px; min-height: 20px; max-height: 20px;}");
    ui->userEdit_lineEdit->setStyleSheet("QLineEdit {font-size: 16px; font-weight: bold; font-family: \"Segoe Print\"; color: #632109; background-color: #DCB66F; border: 2px solid #632109;"
                                         "min-height: 20px; max-height: 20px; min-width: 120px; max-width: 120px;}");
    ui->userName2_label->setStyleSheet("font-size: 18px; font-family: \"Segoe Print\"; color: #632109; font-weight: bold;");

    ui->price_label->setAlignment(Qt::AlignCenter);
    ui->price_label->setStyleSheet("QLabel {font-weight: bold; font-size: 18px}");
    ui->from_label->setAlignment(Qt::AlignCenter);
    ui->to_label->setAlignment(Qt::AlignCenter);


    QIntValidator *validator = new QIntValidator(0, INT_MAX, this); // Пример: разрешаем ввод от 0 до 100
    ui->from_lineEdit->setValidator(validator);
    ui->to_lineEdit->setValidator(validator);

    //LOADING FROM FILES
    //BAYAN
    file.open("../../bayan.txt");
    if (!file.is_open()) qDebug() << "bayan error";

    while (std::getline(file, line)){
        Bayan t ("0", "0", 0, 0, false);
        bayan.push_back(t);
        bayan.back().fromString(line);
    }
    file.close();
    ui->bayanCount_label->setText(QString::number(bayan.size()));

    //CYMBALS
    file.open("../../cymbals.txt");
    if (!file.is_open()) qDebug() << "cymbals error";

    while (std::getline(file, line)){
        Cymbals t ("0", "0", 0, 0);
        cymbals.push_back(t);
        cymbals.back().fromString(line);
    }
    file.close();
    ui->cymbalsCount_label->setText(QString::number(cymbals.size()));

    //DRUMS
    file.open("../../drums.txt");
    if (!file.is_open()) qDebug() << "drums error";

    while (std::getline(file, line)){
        Drums t ("0", "0", 0, 0, "0", false);
        drums.push_back(t);
        drums.back().fromString(line);
    }
    file.close();
    ui->drumsCount_label->setText(QString::number(drums.size()));

    //TRUMPET
    file.open("../../trumpet.txt");
    if (!file.is_open()) qDebug() << "trumpet error";

    while (std::getline(file, line)){
        Trumpet t ("0", "0", 0, 0, "0", "0");
        trumpet.push_back(t);
        trumpet.back().fromString(line);
    }
    file.close();
    ui->trumpetCount_label->setText(QString::number(trumpet.size()));

    //GUITAR
    file.open("../../guitar.txt");
    if (!file.is_open()) qDebug() << "guitar error";

    while (std::getline(file, line)){
        Guitar t ("0", "0", 0, 0, 0, false);
        guitar.push_back(t);
        guitar.back().fromString(line);
    }
    file.close();
    ui->guitarCount_label->setText(QString::number(guitar.size()));


    //VIOLIN
    file.open("../../violin.txt");
    if (!file.is_open()) qDebug() << "violin error";

    while (std::getline(file, line)){
        Violin t ("0", "0", 0, 0, 0, "0", false);
        violin.push_back(t);
        violin.back().fromString(line);
    }
    file.close();
    ui->violinCount_label->setText(QString::number(violin.size()));

    //PIANO
    file.open("../../piano.txt");
    if (!file.is_open()) qDebug() << "piano error";

    while (std::getline(file, line)){
        Piano t ("0", "0", 0, 0, 0);
        piano.push_back(t);
        piano.back().fromString(line);
    }
    file.close();
    ui->pianoCount_label->setText(QString::number(piano.size()));

    ui->stringedCount_label->setText(QString::number(guitar.size()+violin.size()));
    ui->windCount_label->setText(QString::number(trumpet.size()+bayan.size()));
    ui->percussionCount_label->setText(QString::number(drums.size()+cymbals.size()));

    for (int i = 0; i < bayan.size(); i++){
        qDebug() << bayan[i].getModel();
    }

    scrollLayout = new QVBoxLayout(ui->musicList_scrollAreaWidgetContents);
    ui->musicList_scrollAreaWidgetContents->setLayout(scrollLayout);
    ui->musicList_scrollArea->setWidget(ui->musicList_scrollAreaWidgetContents);
    ui->musicList_scrollArea->setWidgetResizable(true);
    scrollLayout->setSpacing(0);
    scrollLayout->setContentsMargins(0,0,0,0);
    QWidget *fillerWidget = new QWidget(ui->musicList_scrollAreaWidgetContents);
    fillerWidget->setStyleSheet("QWidget {border: 2px solid #632109;}");
    scrollLayout->addWidget(fillerWidget);


    ///////////////////
    /// CHOOSE_PAGE ///
    ///////////////////

    ui->okBack_stackedWidget->setCurrentIndex(1);

   ui->nameApp3->setStyleSheet("color: #632109; font-size: 64px; font-family: \"Segoe Print\"; font-weight: bold"); ui->nameApp3->setAlignment(Qt::AlignCenter);
   ui->instrumentManager_sacketWidget->setStyleSheet("QPushButton {font-size: 18px; font-family: \"Segoe Print\"; color: #632109; font-weight: bold; background-color: #DCB66F; border: 2px solid #632109; "
                                        "min-width: 125px; max-width: 125px; min-height: 75px; max-height: 75px;}"
                                                     "QLabel {color: #632109; font-size: 48px; font-family: \"Segoe Print\"; font-weight: bold;}"
                                                     "QLineEdit {font-size: 18px; font-family: \"Segoe Print\"; color: #632109; font-weight: bold; background-color: #DCB66F; border: 1px solid #632109;"
                                        "min-height: 25px; max-height: 25px;}"
                                                     " QCheckBox::indicator {background-color: #DCB66F; border: 1px solid #632109; }"
                                                     "QCheckBox::indicator:checked {"
                                                     "background-color: #DCB66F; border: 2px solid #632109;"
                                                     "image: url(../../img/noteForCheckBox.png);"
                                                     "width: 14px; height: 14px;}"
                                                     "QCheckBox {color: #632109; font-weight: bold; font-size: 16px; font-family: \"Segoe Print\";}"
                                                     );

   ui->guitarName_label->setAlignment(Qt::AlignCenter);
   ui->guitarModel_lineEdit->setAlignment(Qt::AlignCenter);
   ui->guitarCount_lineEdit->setAlignment(Qt::AlignCenter);   ui->guitarCount_lineEdit->setValidator(validator);
   ui->guitarPrice_lineEdit->setAlignment(Qt::AlignCenter);   ui->guitarPrice_lineEdit->setValidator(validator);
   ui->guitarMaterial_lineEdit->setAlignment(Qt::AlignCenter);
   ui->guitarCOString_lineEdit->setAlignment(Qt::AlignCenter);   ui->guitarCOString_lineEdit->setValidator(validator);

   ui->violinName_label_2->setAlignment(Qt::AlignCenter);
   ui->violinCount_lineEdit_2->setAlignment(Qt::AlignCenter);   ui->violinCount_lineEdit_2->setValidator(validator);
   ui->violinModel_lineEdit_2->setAlignment(Qt::AlignCenter);
   ui->violinMaterial_lineEdit_2->setAlignment(Qt::AlignCenter);
   ui->violinPrice_lineEdit_2->setAlignment(Qt::AlignCenter);    ui->violinPrice_lineEdit_2->setValidator(validator);
   ui->violinCOString_lineEdit_2->setAlignment(Qt::AlignCenter);   ui->violinCOString_lineEdit_2->setValidator(validator);
   ui->drumsName_label_3->setAlignment(Qt::AlignCenter);
   ui->drumsCount_lineEdit_3->setAlignment(Qt::AlignCenter);   ui->drumsCount_lineEdit_3->setValidator(validator);
   ui->drumsModel_lineEdit_3->setAlignment(Qt::AlignCenter);
   ui->drumsMaterial_lineEdit_3->setAlignment(Qt::AlignCenter);
   ui->drumsPrice_lineEdit_3->setAlignment(Qt::AlignCenter);   ui->drumsPrice_lineEdit_3->setValidator(validator);
   ui->drumsType_lineEdit_3->setAlignment(Qt::AlignCenter);

   ui->cymbalsName_label_4->setAlignment(Qt::AlignCenter);
   ui->cymbalsModel_lineEdit_4->setAlignment(Qt::AlignCenter);
   ui->cymbalsCount_lineEdit_4->setAlignment(Qt::AlignCenter);   ui->cymbalsCount_lineEdit_4->setValidator(validator);
   ui->cymbalsPrice_lineEdit_4->setAlignment(Qt::AlignCenter);   ui->cymbalsPrice_lineEdit_4->setValidator(validator);
   ui->cymbalsMaterial_lineEdit_4->setAlignment(Qt::AlignCenter);

   ui->trumpetName_label_4->setAlignment(Qt::AlignCenter);
   ui->trumpetModel_lineEdit_4->setAlignment(Qt::AlignCenter);
   ui->trumpetCount_lineEdit_4->setAlignment(Qt::AlignCenter);   ui->trumpetCount_lineEdit_4->setValidator(validator);
   ui->trumpetPrice_lineEdit_4->setAlignment(Qt::AlignCenter);   ui->trumpetPrice_lineEdit_4->setValidator(validator);
   ui->trumpetType_lineEdit_4->setAlignment(Qt::AlignCenter);
   ui->trumpetBuild_lineEdit_4->setAlignment(Qt::AlignCenter);
   ui->trumpetMaterial_lineEdit_4->setAlignment(Qt::AlignCenter);

   ui->bayanName_label_4->setAlignment(Qt::AlignCenter);
   ui->bayanCount_lineEdit_4->setAlignment(Qt::AlignCenter);   ui->bayanCount_lineEdit_4->setValidator(validator);
   ui->bayanModel_lineEdit_4->setAlignment(Qt::AlignCenter);
   ui->bayanPrice_lineEdit_4->setAlignment(Qt::AlignCenter);   ui->bayanPrice_lineEdit_4->setValidator(validator);
   ui->bayanMaterial_lineEdit_4->setAlignment(Qt::AlignCenter);

   ui->pianoName_label_5->setAlignment(Qt::AlignCenter);
   ui->pianoCount_lineEdit_5->setAlignment(Qt::AlignCenter);   ui->pianoCount_lineEdit_5->setValidator(validator);
   ui->pianoModel_lineEdit_5->setAlignment(Qt::AlignCenter);
   ui->pianoPrice_lineEdit_5->setAlignment(Qt::AlignCenter);   ui->pianoPrice_lineEdit_5->setValidator(validator);
   ui->pianoMaterial_lineEdit_5->setAlignment(Qt::AlignCenter);
   ui->pianoCOKeys_lineEdit_5->setAlignment(Qt::AlignCenter);   ui->pianoCOKeys_lineEdit_5->setValidator(validator);





   ui->guitarModel_lineEdit->setPlaceholderText("Model");
   ui->guitarCount_lineEdit->setPlaceholderText("Count");
   ui->guitarPrice_lineEdit->setPlaceholderText("Price");
   ui->guitarMaterial_lineEdit->setPlaceholderText("Material");
   ui->guitarCOString_lineEdit->setPlaceholderText("Count of string");

   ui->violinCount_lineEdit_2->setPlaceholderText("Count");
   ui->violinModel_lineEdit_2->setPlaceholderText("Model");
   ui->violinMaterial_lineEdit_2->setPlaceholderText("Material");
   ui->violinPrice_lineEdit_2->setPlaceholderText("Price");
   ui->violinCOString_lineEdit_2->setPlaceholderText("Count of string");

   ui->drumsCount_lineEdit_3->setPlaceholderText("Count");
   ui->drumsModel_lineEdit_3->setPlaceholderText("Model");
   ui->drumsMaterial_lineEdit_3->setPlaceholderText("Material");
   ui->drumsPrice_lineEdit_3->setPlaceholderText("Price");
   ui->drumsType_lineEdit_3->setPlaceholderText("Type");

   ui->cymbalsModel_lineEdit_4->setPlaceholderText("Model");
   ui->cymbalsCount_lineEdit_4->setPlaceholderText("Count");
   ui->cymbalsPrice_lineEdit_4->setPlaceholderText("Price");
   ui->cymbalsMaterial_lineEdit_4->setPlaceholderText("Material");

   ui->trumpetModel_lineEdit_4->setPlaceholderText("Model");
   ui->trumpetCount_lineEdit_4->setPlaceholderText("Count");
   ui->trumpetPrice_lineEdit_4->setPlaceholderText("Price");
   ui->trumpetType_lineEdit_4->setPlaceholderText("Type");
   ui->trumpetBuild_lineEdit_4->setPlaceholderText("Build");
   ui->trumpetMaterial_lineEdit_4->setPlaceholderText("Material");

   ui->bayanCount_lineEdit_4->setPlaceholderText("Count");
   ui->bayanModel_lineEdit_4->setPlaceholderText("Model");
   ui->bayanPrice_lineEdit_4->setPlaceholderText("Price");
   ui->bayanMaterial_lineEdit_4->setPlaceholderText("Material");

   ui->pianoCount_lineEdit_5->setPlaceholderText("Count");
   ui->pianoModel_lineEdit_5->setPlaceholderText("Model");
   ui->pianoPrice_lineEdit_5->setPlaceholderText("Price");
   ui->pianoMaterial_lineEdit_5->setPlaceholderText("Material");
   ui->pianoCOKeys_lineEdit_5->setPlaceholderText("Count of keys");


   ui->okBack_stackedWidget->setStyleSheet("QPushButton {font-size: 18px; font-family: \"Segoe Print\"; color: #632109; font-weight: bold; background-color: #DCB66F; border: 2px solid #632109; "
                                           "min-width: 100px; max-width: 100px; min-height: 50px; max-height: 50px;}");
   ui->removable_lable->setStyleSheet("color: #632109; font-size: 32px; font-family: \"Segoe Print\"; font-weight: bold"); ui->removable_lable->setAlignment(Qt::AlignCenter);


   ui->removable_lineEdit->setAlignment(Qt::AlignCenter);
}

MainWindow::~MainWindow()
{
    loadUsers(&users);

    std::string line;
    std::ofstream file;
    //LOADING TO FILES
    //BAYAN
    file.open("../../bayan.txt");
    if (!file.is_open()) qDebug() << "bayan error";

    for (int i = 0; i < bayan.size(); i++){
        file << bayan[i].toString() << "\n";
    }
    file.close();

    //CYMBALS
    file.open("../../cymbals.txt");
    if (!file.is_open()) qDebug() << "cymbals error";

    for (int i = 0; i < cymbals.size(); i++){
        file << cymbals[i].toString() << "\n";
    }
    file.close();

    //DRUMS
    file.open("../../drums.txt");
    if (!file.is_open()) qDebug() << "drums error";

    for (int i = 0; i < drums.size(); i++){
        file << drums[i].toString() << "\n";
    }
    file.close();

    //TRUMPET
    file.open("../../trumpet.txt");
    if (!file.is_open()) qDebug() << "trumpet error";

    for (int i = 0; i < trumpet.size(); i++){
        file << trumpet[i].toString() << "\n";
    }
    file.close();

    //GUITAR
    file.open("../../guitar.txt");
    if (!file.is_open()) qDebug() << "guitar error";

    for (int i = 0; i < guitar.size(); i++){
        file << guitar[i].toString() << "\n";
    }
    file.close();


    //VIOLIN
    file.open("../../violin.txt");
    if (!file.is_open()) qDebug() << "violin error";

    for (int i = 0; i < violin.size(); i++){
        file << violin[i].toString() << "\n";
    }
    file.close();

    //PIANO
    file.open("../../piano.txt");
    if (!file.is_open()) qDebug() << "piano error";

    for (int i = 0; i < piano.size(); i++){
        file << piano[i].toString() << "\n";
    }
    file.close();
    delete ui;
}

void MainWindow::on_LogIn_button_clicked()
{
    QString lg = ui->loginEdit->text();
    QString ps = ui->passEdit->text();

    std::string login = lg.toStdString();
    std::string pass = ps.toStdString();

    bool mode;

    pass = hashPassword(pass);

    qDebug() << pass;

    if (login.empty() or pass.empty()){
        QMessageBox::critical(this, "Error!", "INVALID!");
        return;
    }

    if(checkPass(login, pass, &mode, &users)){
        this->user.setLoginPass(login,pass,mode);
        ui->userName->setText(QString::fromStdString(login));
        ui->MusiChoose->setCurrentIndex(1);
        if (mode){
            ui->adminPanel->setCurrentIndex(1);
        } else {
            ui->adminPanel->setCurrentIndex(0);
        }
        ui->loginEdit->clear();
        ui->passEdit->clear();
        ui->visiblePass_checkbox->setChecked(false);
    } else{
        QMessageBox::critical(this, "Error!", "Wrong login or password!");
        return;
    }
}

void MainWindow::on_SignUp_clicked()
{
    std::string login = ui->loginEdit->text().toStdString();
    std::string pass = ui->passEdit->text().toStdString();

    bool mode = false;



    if (login.empty() or pass.empty()){
        QMessageBox::critical(this, "Error!", "INVALID!");
        return;
    }

    if (login.size() > 16){
        QMessageBox::critical(this, "Error!", "Your login is too long!");
        return;
    }

    if(pass.size() < 3){
        QMessageBox::critical(this, "Error!", "The password length is less than 3!");
        return;
    }

    pass = hashPassword(pass);

    qDebug() << pass;

    if(is_exist(login, &mode, &users)){
        QMessageBox::critical(this, "Error!", "This user exist now!");
        return;
    } else{
        ui->userName->setText(QString::fromStdString(login));
        this->user.setLoginPass(login,pass,mode);
        writeUser(login, pass, mode, &users);
        ui->MusiChoose->setCurrentIndex(1);
        ui->loginEdit->clear();
        ui->passEdit->clear();
        ui->visiblePass_checkbox->setChecked(false);
    }

}

void MainWindow::on_backToLogIn_button_clicked()
{
    ui->MusiChoose->setCurrentIndex(0);
    ui->adminPanel->setCurrentIndex(0);
    ui->userEdit_lineEdit->clear();
}


void MainWindow::on_refresh_button_clicked()
{
    bool tr = false, by = false, dr = false, cy = false, pi = false, gu = false, vi = false;
    std::string str_from_price = (ui->from_lineEdit->text()).toStdString(), str_to_price = (ui->to_lineEdit->text()).toStdString();
    int from_price = (ui->from_lineEdit->text()).toInt(), to_price = (ui->to_lineEdit->text()).toInt();
    if (str_from_price.empty()){
        from_price = 0;
    }
    if(str_to_price.empty()){
        to_price = INT_MAX;
    }

    QLayoutItem *child;
    while ((child = scrollLayout->takeAt(0)) != nullptr) {
        if (child->widget()) {
            delete child->widget();
        }
        delete child;
    }


    if (ui->wind_checkBox->isChecked()){
        tr = true;
        by = true;
    } else{
        if (ui->trumpet_checkBox->isChecked()){
            tr = true;
        }
        if (ui->bayan_checkBox->isChecked()){
            by = true;
        }
    }

    if (ui->stringed_checkBox->isChecked()){
        gu = true;
        vi = true;
    } else{
        if (ui->guitar_checkBox->isChecked()){
            gu = true;
        }
        if (ui->violin_checkBox->isChecked()){
            vi = true;
        }
    }

    if (ui->percussion_checkBox->isChecked()){
        dr = true;
        cy= true;
    }else {
        if (ui->drums_checkBox->isChecked()){
            dr = true;
        }
        if (ui->cymbals_checkBox->isChecked()){
            cy = true;
        }
    }

    if (ui->piano_checkBox->isChecked()){
        pi = true;
    }

    if (gu){
        for (int i = 0; i < guitar.size(); i++) {

            if (!(guitar[i].getPrice() <= to_price and guitar[i].getPrice() >= from_price)){
                continue;
            }

            QWidget *instrumentWidget = new QWidget(ui->musicList_scrollAreaWidgetContents);
            QHBoxLayout *instrumentLayout = new QHBoxLayout(instrumentWidget);
            instrumentLayout->setSpacing(5);
            instrumentLayout->setContentsMargins(5,5,0,5);

            QLabel *imageLabel = new QLabel(instrumentWidget);
            imageLabel->setPixmap(QPixmap("../../img/img_guitar.png").scaled(90, 90));

            std::string b;
            if (guitar[i].getElec() == 0){
                b = "NO";
            } else{
                b = "YES";
            }

            QLabel *infoLabel = new QLabel(
                QString("Model: %1\nPrice: %2\nCount: %3\nMaterial: %4\nStrings: %5\nElec: %6")
                    .arg(QString::fromStdString(guitar[i].getModel()))
                    .arg(guitar[i].getPrice())
                    .arg(guitar[i].getCount())
                    .arg(QString::fromStdString(guitar[i].getMaterial()))
                    .arg(guitar[i].GetCOString())
                    .arg(QString::fromStdString(b)), instrumentWidget);
            infoLabel->setAlignment(Qt::AlignLeft);
            instrumentLayout->addWidget(imageLabel);
            instrumentLayout->addWidget(infoLabel);
            instrumentLayout->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));

            instrumentWidget->setStyleSheet("QWidget {border: 2px solid #632109; max-height: 190px} QLabel {border: 0px solid #632109}");

            scrollLayout->addWidget(instrumentWidget);
        }
    }

    if (vi) {
        for (int i = 0; i < violin.size(); i++) {

            if (!(violin[i].getPrice() <= to_price and violin[i].getPrice() >= from_price)){
                continue;
            }

            std::string b;
            if (violin[i].getSmich() == 0){
                b = "NO";
            } else{
                b = "YES";
            }

            QWidget *instrumentWidget = new QWidget(ui->musicList_scrollAreaWidgetContents);
            QHBoxLayout *instrumentLayout = new QHBoxLayout(instrumentWidget);
            instrumentLayout->setSpacing(5);
            instrumentLayout->setContentsMargins(5,5,0,5);

            QLabel *imageLabel = new QLabel(instrumentWidget);
            imageLabel->setPixmap(QPixmap("../../img/img_violin.png").scaled(90, 90));

            QLabel *infoLabel = new QLabel(
                QString("Model: %1\nPrice: %2\nCount: %3\nMaterial: %4\nString: %5\nSmich: %6")
                    .arg(QString::fromStdString(violin[i].getModel()))
                    .arg(violin[i].getPrice())
                    .arg(violin[i].getCount())
                    .arg(QString::fromStdString(violin[i].getMaterial()))
                    .arg(violin[i].GetCOString())
                    .arg(QString::fromStdString(b)), instrumentWidget);
            infoLabel->setAlignment(Qt::AlignLeft);
            instrumentLayout->addWidget(imageLabel);
            instrumentLayout->addWidget(infoLabel);
            instrumentLayout->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));

            instrumentWidget->setStyleSheet("QWidget {border: 2px solid #632109; max-height: 190px} QLabel {border: 0px solid #632109}");

            scrollLayout->addWidget(instrumentWidget);
        }
    }

    if (dr){
        for (int i = 0; i < drums.size(); i++) {

            if (!(drums[i].getPrice() <= to_price and drums[i].getPrice() >= from_price)){
                continue;
            }

            std::string b;
            if (violin[i].getSmich() == 0){
                b = "NO";
            } else{
                b = "YES";
            }

            QWidget *instrumentWidget = new QWidget(ui->musicList_scrollAreaWidgetContents);
            QHBoxLayout *instrumentLayout = new QHBoxLayout(instrumentWidget);
            instrumentLayout->setSpacing(5);
            instrumentLayout->setContentsMargins(5,5,0,5);

            QLabel *imageLabel = new QLabel(instrumentWidget);
            imageLabel->setPixmap(QPixmap("../../img/img_drums.png").scaled(90, 90));

            QLabel *infoLabel = new QLabel(
                QString("Model: %1\nPrice: %2\nCount: %3\nType: %4\nMaterial: %5\nSticks: %6")
                    .arg(QString::fromStdString(drums[i].getModel()))
                    .arg(drums[i].getPrice())
                    .arg(drums[i].getCount())
                    .arg(QString::fromStdString(drums[i].getType()))
                    .arg(QString::fromStdString(drums[i].getMaterial()))
                    .arg(QString::fromStdString(b)), instrumentWidget);
            infoLabel->setAlignment(Qt::AlignLeft);
            instrumentLayout->addWidget(imageLabel);
            instrumentLayout->addWidget(infoLabel);
            instrumentLayout->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));

            instrumentWidget->setStyleSheet("QWidget {border: 2px solid #632109; max-height: 190px} QLabel {border: 0px solid #632109}");

            scrollLayout->addWidget(instrumentWidget);
        }
    }

    if (cy){
        for (int i = 0; i < cymbals.size(); i++) {

            if (!(cymbals[i].getPrice() <= to_price and cymbals[i].getPrice() >= from_price)){
                continue;
            }

            QWidget *instrumentWidget = new QWidget(ui->musicList_scrollAreaWidgetContents);
            QHBoxLayout *instrumentLayout = new QHBoxLayout(instrumentWidget);
            instrumentLayout->setSpacing(5);
            instrumentLayout->setContentsMargins(5,5,0,5);

            QLabel *imageLabel = new QLabel(instrumentWidget);
            imageLabel->setPixmap(QPixmap("../../img/img_cymbals.png").scaled(90, 90));

            QLabel *infoLabel = new QLabel(
                QString("Model: %1\nPrice: %2\nCount: %3\nMaterial: %4")
                    .arg(QString::fromStdString(cymbals[i].getModel()))
                    .arg(cymbals[i].getPrice())
                    .arg(cymbals[i].getCount())
                    .arg(QString::fromStdString(cymbals[i].getMaterial())), instrumentWidget);
            infoLabel->setAlignment(Qt::AlignLeft);
            instrumentLayout->addWidget(imageLabel);
            instrumentLayout->addWidget(infoLabel);
            instrumentLayout->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));

            instrumentWidget->setStyleSheet("QWidget {border: 2px solid #632109; max-height: 126px} QLabel {border: 0px solid #632109}");

            scrollLayout->addWidget(instrumentWidget);
        }
    }

    if (tr){
        for (int i = 0; i < trumpet.size(); i++) {

            if (!(trumpet[i].getPrice() <= to_price and trumpet[i].getPrice() >= from_price)){
                continue;
            }

            QWidget *instrumentWidget = new QWidget(ui->musicList_scrollAreaWidgetContents);
            QHBoxLayout *instrumentLayout = new QHBoxLayout(instrumentWidget);
            instrumentLayout->setSpacing(5);
            instrumentLayout->setContentsMargins(5,5,0,5);

            QLabel *imageLabel = new QLabel(instrumentWidget);
            imageLabel->setPixmap(QPixmap("../../img/img_trumpet.png").scaled(90, 90));

            QLabel *infoLabel = new QLabel(
                QString("Model: %1\nPrice: %2\nCount: %3\nType: %4\nBuild: #%5\nMaterial: %6")
                    .arg(QString::fromStdString(trumpet[i].getModel()))
                    .arg(trumpet[i].getPrice())
                    .arg(trumpet[i].getCount())
                    .arg(QString::fromStdString(trumpet[i].getType()))
                    .arg(QString::fromStdString(trumpet[i].getBuild()))
                    .arg(QString::fromStdString(trumpet[i].getMaterial())), instrumentWidget);
            infoLabel->setAlignment(Qt::AlignLeft);
            instrumentLayout->addWidget(imageLabel);
            instrumentLayout->addWidget(infoLabel);
            instrumentLayout->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));

            instrumentWidget->setStyleSheet("QWidget {border: 2px solid #632109; max-height: 190px} QLabel {border: 0px solid #632109}");

            scrollLayout->addWidget(instrumentWidget);
        }
    }

    if (by){
        for (int i = 0; i < bayan.size(); i++) {

            if (!(bayan[i].getPrice() <= to_price and bayan[i].getPrice() >= from_price)){
                continue;
            }

            std::string b;
            if (bayan[i].getKeys() == 0){
                b = "NO";
            } else{
                b = "YES";
            }

            QWidget *instrumentWidget = new QWidget(ui->musicList_scrollAreaWidgetContents);
            QHBoxLayout *instrumentLayout = new QHBoxLayout(instrumentWidget);
            instrumentLayout->setSpacing(5);
            instrumentLayout->setContentsMargins(5,5,0,5);

            QLabel *imageLabel = new QLabel(instrumentWidget);
            imageLabel->setPixmap(QPixmap("../../img/img_bayan.png").scaled(90, 90));

            QLabel *infoLabel = new QLabel(
                QString("Model: %1\nPrice: %2\nCount: %3\nMaterial: %4\nKeys: %5")
                    .arg(QString::fromStdString(bayan[i].getModel()))
                    .arg(bayan[i].getPrice())
                    .arg(bayan[i].getCount())
                    .arg(QString::fromStdString(bayan[i].getMaterial()))
                    .arg(QString::fromStdString(b)), instrumentWidget);
            infoLabel->setAlignment(Qt::AlignLeft);
            instrumentLayout->addWidget(imageLabel);
            instrumentLayout->addWidget(infoLabel);
            instrumentLayout->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));

            instrumentWidget->setStyleSheet("QWidget {border: 2px solid #632109; max-height: 130px} QLabel {border: 0px solid #632109}");

            scrollLayout->addWidget(instrumentWidget);


        }
    }

    if (pi){
        for (int i = 0; i < piano.size(); i++) {

            if (!(piano[i].getPrice() <= to_price and piano[i].getPrice() >= from_price)){
                continue;
            }

            QWidget *instrumentWidget = new QWidget(ui->musicList_scrollAreaWidgetContents);
            QHBoxLayout *instrumentLayout = new QHBoxLayout(instrumentWidget);
            instrumentLayout->setSpacing(5);
            instrumentLayout->setContentsMargins(5,5,0,5);

            QLabel *imageLabel = new QLabel(instrumentWidget);
            imageLabel->setPixmap(QPixmap("../../img/img_piano.png").scaled(90, 90));

            QLabel *infoLabel = new QLabel(
                QString("Model: %1\nPrice: %2\nCount: %3\nCount of keys: %4\nMaterial: %5")
                    .arg(QString::fromStdString(piano[i].getModel()))
                    .arg(piano[i].getPrice())
                    .arg(piano[i].getCount())
                    .arg(piano[i].getCOKeys())
                    .arg(QString::fromStdString(trumpet[i].getMaterial())), instrumentWidget);
            infoLabel->setAlignment(Qt::AlignLeft);
            instrumentLayout->addWidget(imageLabel);
            instrumentLayout->addWidget(infoLabel);
            instrumentLayout->addItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));

            instrumentWidget->setStyleSheet("QWidget {border: 2px solid #632109; max-height: 130px} QLabel {border: 0px solid #632109}");

            scrollLayout->addWidget(instrumentWidget);
        }
    }

    ui->stringedCount_label->setText(QString::number(guitar.size()+violin.size()));
    ui->windCount_label->setText(QString::number(trumpet.size()+bayan.size()));
    ui->percussionCount_label->setText(QString::number(drums.size()+cymbals.size()));
    ui->bayanCount_label->setText(QString::number(bayan.size()));
    ui->cymbalsCount_label->setText(QString::number(cymbals.size()));
    ui->drumsCount_label->setText(QString::number(drums.size()));
    ui->trumpetCount_label->setText(QString::number(trumpet.size()));
    ui->guitarCount_label->setText(QString::number(guitar.size()));
    ui->violinCount_label->setText(QString::number(violin.size()));
    ui->pianoCount_label->setText(QString::number(piano.size()));

    QWidget *fillerWidget = new QWidget(ui->musicList_scrollAreaWidgetContents);
    fillerWidget->setStyleSheet("QWidget {border: 2px solid #632109;}");
    scrollLayout->addWidget(fillerWidget);
}


void MainWindow::on_visiblePass_checkbox_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked){
        ui->passEdit->setEchoMode(QLineEdit::Normal);
    } else {
        ui->passEdit->setEchoMode(QLineEdit::Password);
    }
}


void MainWindow::on_userControl_pushButton_clicked()
{
    ui->adminPanel->setCurrentIndex(2);
}


void MainWindow::on_instrumentControl_pushButton_clicked()
{
    ui->adminPanel->setCurrentIndex(3);
}



void MainWindow::on_backToUsIn1_pushButton_clicked()
{
    ui->adminPanel->setCurrentIndex(1);
}

void MainWindow::on_backToUsIn2_pushButton_clicked()
{
    ui->adminPanel->setCurrentIndex(1);
}


void MainWindow::on_addUser_pushButton_clicked()
{
    ui->adminPanel->setCurrentIndex(4);
    user_mode = 0;

}

void MainWindow::on_backToUs1_pushButton_clicked()
{
    ui->adminPanel->setCurrentIndex(2);
    ui->userEdit_lineEdit->clear();
}

void MainWindow::on_deleteUser_pushButton_clicked()
{
    ui->adminPanel->setCurrentIndex(4);
    user_mode = 1;
}

void MainWindow::on_ok_pushButton_clicked()
{
    std::string login = (ui->userEdit_lineEdit->text()).toStdString();
    if (login.empty()){
        QMessageBox::critical(this, "Error!", "INVALID!");
        return;
    }
    else if (users[login].first.empty()){
        QMessageBox::critical(this, "Error!", "This user is not exist!");
        return;

    }else if (login == user.getLogin()) {
        QMessageBox::critical(this, "Error!", "You cant do this with yourself!");
        return;
    }
        else {
        if (user_mode == 0){
            if (users[login].second == 0){
                users[login].second = 1;
                QMessageBox::about(this, "Admin", QString::fromStdString(login + " now is admin"));
            } else {
                users[login].second = 0;
                QMessageBox::about(this, "User", QString::fromStdString(login + " now is user"));
            }
        } else {
            users[login].first = "";
            users[login].second = 0;
            QMessageBox::about(this, "Delete", QString::fromStdString(login + " is deleted"));
            ui->userEdit_lineEdit->clear();
        }
    }
}

void MainWindow::on_addInstrument_pushButton_clicked()
{
    user_mode = 0;
    ui->MusiChoose->setCurrentIndex(2);
    ui->instrumentManager_sacketWidget->setCurrentIndex(0);
}

void MainWindow::on_deleteInstrument_pushButton_clicked()
{
    user_mode = 1;
    ui->MusiChoose->setCurrentIndex(2);
    ui->instrumentManager_sacketWidget->setCurrentIndex(0);
}

void MainWindow::on_backTo2page_pushButton_clicked()
{
    ui->MusiChoose->setCurrentIndex(1);

    ui->guitarModel_lineEdit->clear();
    ui->guitarCount_lineEdit->clear();
    ui->guitarPrice_lineEdit->clear();
    ui->guitarMaterial_lineEdit->clear();
    ui->guitarCOString_lineEdit->clear();

    ui->violinCount_lineEdit_2->clear();
    ui->violinModel_lineEdit_2->clear();
    ui->violinMaterial_lineEdit_2->clear();
    ui->violinPrice_lineEdit_2->clear();
    ui->violinCOString_lineEdit_2->clear();

    ui->drumsCount_lineEdit_3->clear();
    ui->drumsModel_lineEdit_3->clear();
    ui->drumsMaterial_lineEdit_3->clear();
    ui->drumsPrice_lineEdit_3->clear();
    ui->drumsType_lineEdit_3->clear();

    ui->cymbalsModel_lineEdit_4->clear();
    ui->cymbalsCount_lineEdit_4->clear();
    ui->cymbalsPrice_lineEdit_4->clear();
    ui->cymbalsMaterial_lineEdit_4->clear();

    ui->trumpetModel_lineEdit_4->clear();
    ui->trumpetCount_lineEdit_4->clear();
    ui->trumpetPrice_lineEdit_4->clear();
    ui->trumpetType_lineEdit_4->clear();
    ui->trumpetBuild_lineEdit_4->clear();
    ui->trumpetMaterial_lineEdit_4->clear();

    ui->bayanCount_lineEdit_4->clear();
    ui->bayanModel_lineEdit_4->clear();
    ui->bayanPrice_lineEdit_4->clear();
    ui->bayanMaterial_lineEdit_4->clear();

    ui->pianoCount_lineEdit_5->clear();
    ui->pianoModel_lineEdit_5->clear();
    ui->pianoPrice_lineEdit_5->clear();
    ui->pianoMaterial_lineEdit_5->clear();
    ui->pianoCOKeys_lineEdit_5->clear();
}

void MainWindow::on_guitar_pushButton_clicked()
{
    inst_mode = 0;
    if (user_mode == 0){
        ui->instrumentManager_sacketWidget->setCurrentIndex(inst_mode+2);
    } else {
        ui->instrumentManager_sacketWidget->setCurrentIndex(1);
    }
    ui->okBack_stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_violin_pushButton_clicked()
{
    inst_mode = 1;
    if (user_mode == 0){
        ui->instrumentManager_sacketWidget->setCurrentIndex(inst_mode+2);
    } else {
        ui->instrumentManager_sacketWidget->setCurrentIndex(1);
    }
    ui->okBack_stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_drums_pushButton_clicked()
{
    inst_mode = 2;
    if (user_mode == 0){
        ui->instrumentManager_sacketWidget->setCurrentIndex(inst_mode+2);
    } else {
        ui->instrumentManager_sacketWidget->setCurrentIndex(1);
    }
    ui->okBack_stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_cymbals_pushButton_clicked()
{
    inst_mode = 3;
    if (user_mode == 0){
        ui->instrumentManager_sacketWidget->setCurrentIndex(inst_mode+2);
    } else {
        ui->instrumentManager_sacketWidget->setCurrentIndex(1);
    }
    ui->okBack_stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_bayan_pushButton_clicked()
{
    inst_mode = 4;
    if (user_mode == 0){
        ui->instrumentManager_sacketWidget->setCurrentIndex(inst_mode+2);
    } else {
        ui->instrumentManager_sacketWidget->setCurrentIndex(1);
    }
    ui->okBack_stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_trumpet_pushButton_clicked()
{
    inst_mode = 5;
    if (user_mode == 0){
        ui->instrumentManager_sacketWidget->setCurrentIndex(inst_mode+2);
    } else {
        ui->instrumentManager_sacketWidget->setCurrentIndex(1);
    }
    ui->okBack_stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_piano_pushButton_clicked()
{
    inst_mode = 6;
    if (user_mode == 0){
        ui->instrumentManager_sacketWidget->setCurrentIndex(inst_mode+2);
    } else {
        ui->instrumentManager_sacketWidget->setCurrentIndex(1);
    }
    ui->okBack_stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_ok2_pushButton_clicked()
{
    if (user_mode == 0){
        if (inst_mode == 0){
            std::string model = (ui->guitarModel_lineEdit->text()).toStdString();
            std::string scount = ui->guitarCount_lineEdit->text().toStdString();
            int count = (ui->guitarCount_lineEdit->text()).toInt();
            std::string sprice = ui->guitarPrice_lineEdit->text().toStdString();
            double price = (ui->guitarPrice_lineEdit->text()).toDouble();
            std::string scountOf = ui->guitarCOString_lineEdit->text().toStdString();
            int countOf = (ui->guitarCOString_lineEdit->text()).toInt();
            std::string material = (ui->guitarMaterial_lineEdit->text()).toStdString();
            int b = ui->guitarElec_checkBox->isChecked();

            if (model.empty() or scount.empty() or sprice.empty() or material.empty() or scountOf.empty()){
                QMessageBox::critical(this, "Error!", "INVALID!");
                return;
            }

            Guitar t (model, material, count, price, countOf, b);
            guitar.push_back(t);

        }
        else if (inst_mode == 1){
            std::string model = (ui->violinModel_lineEdit_2->text()).toStdString();
            std::string scount = ui->violinCount_lineEdit_2->text().toStdString();
            int count = (ui->violinCount_lineEdit_2->text()).toInt();
            std::string sprice = ui->violinPrice_lineEdit_2->text().toStdString();
            double price = (ui->violinPrice_lineEdit_2->text()).toDouble();
            std::string scountOf = ui->violinCOString_lineEdit_2->text().toStdString();
            int countOf = (ui->violinCOString_lineEdit_2->text()).toInt();
            std::string material = (ui->violinMaterial_lineEdit_2->text()).toStdString();
            int b = ui->violinSmich_checkBox_2->isChecked();

            if (model.empty() or scount.empty() or sprice.empty() or material.empty() or scountOf.empty()){
                QMessageBox::critical(this, "Error!", "INVALID!");
                return;
            }

            Violin t (model, material, count, price, countOf, "0", b);
            violin.push_back(t);
        }
        else if (inst_mode == 2){
            std::string model = (ui->drumsModel_lineEdit_3->text()).toStdString();
            std::string scount = ui->drumsCount_lineEdit_3->text().toStdString();
            int count = (ui->drumsCount_lineEdit_3->text()).toInt();
            std::string sprice = ui->drumsPrice_lineEdit_3->text().toStdString();
            double price = (ui->drumsPrice_lineEdit_3->text()).toDouble();
            std::string type = ui->drumsType_lineEdit_3->text().toStdString();
            std::string material = (ui->drumsMaterial_lineEdit_3->text()).toStdString();
            int b = ui->drumsSticks_checkBox_3->isChecked();

            if (model.empty() or scount.empty() or sprice.empty() or material.empty() or type.empty()){
                QMessageBox::critical(this, "Error!", "INVALID!");
                return;
            }

            Drums t (model, material, count, price, type, b);
            drums.push_back(t);
        }
        else if (inst_mode == 3){
            std::string model = (ui->cymbalsModel_lineEdit_4->text()).toStdString();
            std::string scount = ui->cymbalsCount_lineEdit_4->text().toStdString();
            int count = (ui->cymbalsCount_lineEdit_4->text()).toInt();
            std::string sprice = ui->cymbalsPrice_lineEdit_4->text().toStdString();
            double price = (ui->cymbalsPrice_lineEdit_4->text()).toDouble();
            std::string material = (ui->cymbalsMaterial_lineEdit_4->text()).toStdString();

            if (model.empty() or scount.empty() or sprice.empty() or material.empty()){
                QMessageBox::critical(this, "Error!", "INVALID!");
                return;
            }

            Cymbals t (model, material, count, price);
            cymbals.push_back(t);
        }
        else if (inst_mode == 4){
            std::string model = (ui->bayanModel_lineEdit_4->text()).toStdString();
            std::string scount = ui->bayanCount_lineEdit_4->text().toStdString();
            int count = (ui->bayanCount_lineEdit_4->text()).toInt();
            std::string sprice = ui->bayanPrice_lineEdit_4->text().toStdString();
            double price = (ui->bayanPrice_lineEdit_4->text()).toDouble();
            std::string material = (ui->bayanMaterial_lineEdit_4->text()).toStdString();
            int b = ui->bayanSticks_checkBox_4->isChecked();

            if (model.empty() or scount.empty() or sprice.empty() or material.empty()){
                QMessageBox::critical(this, "Error!", "INVALID!");
                return;
            }

            Bayan t (model, material, count, price, b);
            bayan.push_back(t);
        }
        else if (inst_mode == 5){
            std::string model = (ui->trumpetModel_lineEdit_4->text()).toStdString();
            std::string scount = ui->trumpetCount_lineEdit_4->text().toStdString();
            int count = (ui->trumpetCount_lineEdit_4->text()).toInt();
            std::string sprice = ui->trumpetPrice_lineEdit_4->text().toStdString();
            double price = (ui->trumpetPrice_lineEdit_4->text()).toDouble();
            std::string type = ui->trumpetType_lineEdit_4->text().toStdString();
            std::string build = ui->trumpetBuild_lineEdit_4->text().toStdString();
            std::string material = (ui->trumpetMaterial_lineEdit_4->text()).toStdString();
            int b = ui->guitarElec_checkBox->isChecked();

            if (model.empty() or scount.empty() or sprice.empty() or material.empty() or type.empty() or build.empty()){
                QMessageBox::critical(this, "Error!", "INVALID!");
                return;
            }

            Trumpet t (model, material, count, price, type, build);
            trumpet.push_back(t);
        }
        else if (inst_mode == 6){
            std::string model = (ui->pianoModel_lineEdit_5->text()).toStdString();
            std::string scount = ui->pianoCount_lineEdit_5->text().toStdString();
            int count = (ui->pianoCount_lineEdit_5->text()).toInt();
            std::string sprice = ui->pianoPrice_lineEdit_5->text().toStdString();
            double price = (ui->pianoPrice_lineEdit_5->text()).toDouble();
            std::string scountOf = ui->pianoCOKeys_lineEdit_5->text().toStdString();
            int countOf = (ui->pianoCOKeys_lineEdit_5->text()).toInt();
            std::string material = (ui->pianoMaterial_lineEdit_5->text()).toStdString();
            int b = ui->guitarElec_checkBox->isChecked();

            if (model.empty() or scount.empty() or sprice.empty() or material.empty() or scountOf.empty()){
                QMessageBox::critical(this, "Error!", "INVALID!");
                return;
            }

            Piano t (model, material, count, price, countOf);
            piano.push_back(t);
        }
        QMessageBox::about(this, "Add", QString::fromStdString("Instrument was added"));
    } else {
        std::string login = (ui->removable_lineEdit->text()).toStdString();

        if (login.empty()){
            QMessageBox::critical(this, "Error!", "INVALID!");
            return;
        }

        if (inst_mode == 0){
            int i;
            for (i = 0; guitar[i].getModel() != login and i < guitar.size(); i++);
            if (i == guitar.size()){
                QMessageBox::critical(this, "Error!", "This intrument is not exist!");
                ui->removable_lineEdit->clear();
                return;
            }
            guitar.erase(guitar.begin()+i);

        }
        else if (inst_mode == 1){
            int i;
            for (i = 0; violin[i].getModel() != login and i < violin.size(); i++);
            if (i == violin.size()){
                QMessageBox::critical(this, "Error!", "This intrument is not exist!");
                ui->removable_lineEdit->clear();
                return;
            }
            violin.erase(violin.begin()+i);
        }
        else if (inst_mode == 2){
            int i;
            for (i = 0; drums[i].getModel() != login and i < drums.size(); i++);
            if (i == drums.size()){
                QMessageBox::critical(this, "Error!", "This intrument is not exist!");
                ui->removable_lineEdit->clear();
                return;
            }
            drums.erase(drums.begin()+i);
        }
        else if (inst_mode == 3){
            int i;
            for (i = 0; cymbals[i].getModel() != login and i < cymbals.size(); i++);
            if (i == cymbals.size()){
                QMessageBox::critical(this, "Error!", "This intrument is not exist!");
                ui->removable_lineEdit->clear();
                return;
            }
            cymbals.erase(cymbals.begin()+i);
        }
        else if (inst_mode == 4){
            int i;
            for (i = 0; bayan[i].getModel() != login and i < bayan.size(); i++);
            if (i == bayan.size()){
                QMessageBox::critical(this, "Error!", "This intrument is not exist!");
                ui->removable_lineEdit->clear();
                return;
            }
            bayan.erase(bayan.begin()+i);
        }
        else if (inst_mode == 5){
            int i;
            for (i = 0; trumpet[i].getModel() != login and i < trumpet.size(); i++);
            if (i == trumpet.size()){
                QMessageBox::critical(this, "Error!", "This intrument is not exist!");
                ui->removable_lineEdit->clear();
                return;
            }
            trumpet.erase(trumpet.begin()+i);
        }
        else if (inst_mode == 6){
            int i;
            for (i = 0; piano[i].getModel() != login and i < piano.size(); i++);
            if (i == piano.size()){
                QMessageBox::critical(this, "Error!", "This intrument is not exist!");
                ui->removable_lineEdit->clear();
                return;
            }
            piano.erase(piano.begin()+i);
        }
        ui->removable_lineEdit->clear();
        QMessageBox::about(this, "Delete", QString::fromStdString(login + " was deleted"));
    }
    MainWindow::on_refresh_button_clicked();

    ui->guitarModel_lineEdit->clear();
    ui->guitarCount_lineEdit->clear();
    ui->guitarPrice_lineEdit->clear();
    ui->guitarMaterial_lineEdit->clear();
    ui->guitarCOString_lineEdit->clear();

    ui->violinCount_lineEdit_2->clear();
    ui->violinModel_lineEdit_2->clear();
    ui->violinMaterial_lineEdit_2->clear();
    ui->violinPrice_lineEdit_2->clear();
    ui->violinCOString_lineEdit_2->clear();

    ui->drumsCount_lineEdit_3->clear();
    ui->drumsModel_lineEdit_3->clear();
    ui->drumsMaterial_lineEdit_3->clear();
    ui->drumsPrice_lineEdit_3->clear();
    ui->drumsType_lineEdit_3->clear();

    ui->cymbalsModel_lineEdit_4->clear();
    ui->cymbalsCount_lineEdit_4->clear();
    ui->cymbalsPrice_lineEdit_4->clear();
    ui->cymbalsMaterial_lineEdit_4->clear();

    ui->trumpetModel_lineEdit_4->clear();
    ui->trumpetCount_lineEdit_4->clear();
    ui->trumpetPrice_lineEdit_4->clear();
    ui->trumpetType_lineEdit_4->clear();
    ui->trumpetBuild_lineEdit_4->clear();
    ui->trumpetMaterial_lineEdit_4->clear();

    ui->bayanCount_lineEdit_4->clear();
    ui->bayanModel_lineEdit_4->clear();
    ui->bayanPrice_lineEdit_4->clear();
    ui->bayanMaterial_lineEdit_4->clear();

    ui->pianoCount_lineEdit_5->clear();
    ui->pianoModel_lineEdit_5->clear();
    ui->pianoPrice_lineEdit_5->clear();
    ui->pianoMaterial_lineEdit_5->clear();
    ui->pianoCOKeys_lineEdit_5->clear();
}

void MainWindow::on_backToInst_pushButton_clicked()
{
    ui->instrumentManager_sacketWidget->setCurrentIndex(0);
    ui->okBack_stackedWidget->setCurrentIndex(1);
}




/////////////
/// WASTE ///
/////////////

void MainWindow::on_pushButton_clicked()
{
    // qDebug() << "Login: " << user.getLogin() << "\nPassword: " << user.getPass() << "\nMode: " << user.getMode() << "\n";
}
void MainWindow::on_visiblePass_checkbox_checkStateChanged(const Qt::CheckState &arg1)
{

}
void MainWindow::on_backToUsIn1_pushButton_2_clicked()
{
    ui->adminPanel->setCurrentIndex(1);
}

void MainWindow::on_pushButton_2_clicked()
{

}

