#include <interface.h>


interface_window::interface_window(){
    // кнопка загрузки файла
    QPushButton *file_upload = new QPushButton("Загрузить файл", this);
    file_upload->setGeometry(100, 50, 100, 30);
    connect(file_upload, &QPushButton::clicked, this, &interface_window::wread_file);

    // срока состояния после загрузки файла
    result = new QLabel("", this);
    result->setGeometry(50, 100, 200, 30);
    result->setAlignment(Qt::AlignCenter);

    // определяем окно
    interface = new QWidget();
    this->resize(300, 200);
    this->setWindowTitle("Главное меню");
}

void interface_window::wread_file(){
    findfile = new QFileDialog();
    file = new QFile();

    QString path =  findfile->getOpenFileName();
    file->setFileName(path);

    if (file->open(QIODevice::ReadOnly)){
        QString a = file->readAll();

        result->clear();
        if (data_checking(a) == false){
            result->setText("Ошибка чтения(data is incorrect)");
        } else {
            result->setText("Данные успешно загружены");
            if (w_graph != nullptr){
                delete w_graph;
            }
            open_graph_window();
        }
    }

    file->close();
    delete findfile;
    delete file;
}

bool interface_window::data_checking(QString str){
    str.replace("\r", " ");
    str.replace("\n", " ");
    QStringList list = str.split(" ", Qt::SkipEmptyParts);
    for(auto i : list){
        if(i!="0" && i!="1"){
            return false;
        }
    }

    graph = new directed_graph(sqrt(list.length()));
    int count = -1;
    for (auto i=0; i <  sqrt(list.length()); i++){
        for (auto j=0; j < sqrt(list.length()); j++){
            count+=1;
            graph->m->set(list[count].toInt(),i,j);
            qDebug() << graph->m->get(i,j);
        }
    }

    return true;
}

void interface_window::open_graph_window(){
    w_graph = new window_graph(graph);
    w_graph->show();
}

interface_window::~interface_window(){
    delete result;
    delete interface;
}
