#include "qboxlayout.h"
#include "user.h"
#include "Instrument.h"
#include "Bayan.h"
#include "Cymbals.h"
#include "Guitar.h"
#include "Drums.h"
#include "Violin.h"
#include "Trumpet.h"
#include "Piano.h"

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qstring.h>
#include <QMessageBox>
#include <QDebug>
#include <QPixmap>
#include <QFont>
#include <QSpacerItem>
#include <QIntValidator>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_LogIn_button_clicked();

    void on_SignUp_clicked();



    void on_pushButton_clicked();

    void on_backToLogIn_button_clicked();

    void on_visiblePass_checkbox_checkStateChanged(const Qt::CheckState &arg1);

    void on_refresh_button_clicked();

    void on_visiblePass_checkbox_stateChanged(int arg1);

    void on_userControl_pushButton_clicked();

    void on_instrumentControl_pushButton_clicked();

    void on_backToUsIn1_pushButton_clicked();

    void on_backToUsIn1_pushButton_2_clicked();

    void on_backToUsIn2_pushButton_clicked();

    void on_addUser_pushButton_clicked();

    void on_backToUs1_pushButton_clicked();

    void on_deleteUser_pushButton_clicked();

    void on_ok_pushButton_clicked();

    void on_addInstrument_pushButton_clicked();

    void on_deleteInstrument_pushButton_clicked();

    void on_backTo2page_pushButton_clicked();

    void on_guitar_pushButton_clicked();

    void on_violin_pushButton_clicked();

    void on_drums_pushButton_clicked();

    void on_cymbals_pushButton_clicked();

    void on_bayan_pushButton_clicked();

    void on_trumpet_pushButton_clicked();

    void on_piano_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_ok2_pushButton_clicked();

    void on_backToInst_pushButton_clicked();

private:

    std::vector<Bayan> bayan;
    std::vector<Cymbals> cymbals;
    std::vector<Guitar> guitar;
    std::vector<Violin> violin;
    std::vector<Trumpet> trumpet;
    std::vector<Drums> drums;
    std::vector<Piano> piano;

    QVBoxLayout *scrollLayout;

    User user;

    int user_mode;
    int inst_mode;

    std::unordered_map<std::string, std::pair<std::string, bool>> users;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
