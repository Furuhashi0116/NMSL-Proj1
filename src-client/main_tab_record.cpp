#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVector>



/**
 * @brief MainWindow::setTableWidget_records
 */
void MainWindow::setTableWidget_records(){
    ui->tableWidget_records->clearContents();

    QApplication::processEvents();
    ui->tableWidget_records->verticalHeader()->setVisible(false); //设置表垂直头不可见

    //根据文本自适应宽度
    //    ui->tableWidget_records->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);    //x先自适应宽度
    //    ui->tableWidget_records->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);

    ui->tableWidget_records->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可编辑,但是不会像设置Enable那样使界面变灰
    ui->tableWidget_records->setRowCount(record_size);//设置行数，与搜索结果size相同
    ui->tableWidget_records->horizontalHeader()->resizeSection(0, 115); //设置列的宽度
    ui->tableWidget_records->horizontalHeader()->resizeSection(1, 230);
    ui->tableWidget_records->horizontalHeader()->resizeSection(2, 115);
    ui->tableWidget_records->horizontalHeader()->resizeSection(3, 115);
    ui->tableWidget_records->horizontalHeader()->resizeSection(4, 115);

    int i=0;//控制总行数
    QVector<Record>::iterator it;
    for(it=qv_record.begin(); it!=qv_record.end(); ++it){
        QMap<QString, QString> m = it->getDetails();
        QMap<QString, QString>::iterator it2;

        ui->tableWidget_records->setItem(i,0,new QTableWidgetItem(it->getIdTrans())); //id_trans
        ui->tableWidget_records->setItem(i,1,new QTableWidgetItem(it->getDate())); //date
        ui->tableWidget_records->setItem(i,2,new QTableWidgetItem(it->getPrices())); //prices

        if(m.size()>1){
            ui->tableWidget_records->setSpan(i, 0, m.size(), 1);
            ui->tableWidget_records->setSpan(i, 1, m.size(), 1);
            ui->tableWidget_records->setSpan(i, 2, m.size(), 1);
        }

        for(it2=m.begin(); it2!=m.end(); ++it2){
            QApplication::processEvents();
            ui->tableWidget_records->setItem(i,3,new QTableWidgetItem(it2.key())); //style
            ui->tableWidget_records->setItem(i,4,new QTableWidgetItem(it2.value())); //amount
            ++i;
        }
    }
}


