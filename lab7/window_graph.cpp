#include "window_graph.h"

#define PI 3.14159265

window_graph::window_graph(directed_graph *new_graph) {
    this->graph = new_graph;

    interface = new QWidget();
    this->resize(500, 500);
    this->setWindowTitle("Граф");
}

void window_graph::paintEvent(QPaintEvent*) {
    QPainter painter(this);

    QPen pen;
    pen.setWidth(3.5);

    painter.setPen(pen);
    painter.setBrush(QBrush(Qt::white));

    //Рисуем вершины графа
    QVector<QVector<double>> points;
    QVector<QVector<double>> points_centre;
    int vertex = 1;
    point_in_elipse(points_centre, 230, 230, 200, graph->m->len());
    for(auto i: points_centre){
        painter.drawEllipse(i[0], i[1], 40, 40);
        painter.drawText(i[0]+15,i[1]+25,QString::number(vertex));
        vertex+=1;
    }

    QBrush brush;
    brush.setColor(Qt::black);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    point_in_elipse(points, 250, 250, 180, graph->m->len());
    for (auto i =0; i < graph->m->len();i++){
        for (auto j=0; j < graph->m->len(); j++){
            if (graph->m->get(i,j) == 1 && i!=j){
                QPoint start(QPoint(points[i][0],points[i][1]));
                QPoint end(QPoint(points[j][0],points[j][1]));
                painter.drawLine(start, end);

                // Считаем угол между линией и осью X
                double angle = std::atan2(end.y() - start.y(), end.x() - start.x());

                // Рисуем стрелку
                int arrow_len = 20;
                QPoint arrow_p1(end.x() - arrow_len * std::cos(angle - M_PI / 18), end.y() - arrow_len * std::sin(angle - M_PI / 18));
                QPoint arrow_p2(end.x() - arrow_len * std::cos(angle + M_PI / 18), end.y() - arrow_len * std::sin(angle + M_PI / 18));
                QPolygonF arrowHead;

                arrowHead << end << arrow_p1 << arrow_p2;

                painter.drawPolygon(arrowHead);

            }
        }
        if(graph->m->get(i,i) == 1){
            if (points_centre[i][1] <= -points_centre[i][0] + 500){
                painter.drawArc(points_centre[i][0] - 10,points_centre[i][1] - 10, 20, 20,0,270*16);
            } else {
                painter.drawArc(points_centre[i][0] + 39.5,points_centre[i][1] + 9.8, 20, 20,270*13.5,270*16);
            }
        }
    }

    QPainter p;
    p.begin(this);
    p.end();
}

void window_graph::point_in_elipse(QVector<QVector<double>>& points, int x0, int y0, int r, int num_point){
    auto x = 0;
    auto y = 0;
    int vertex = 1;
    for(int i = 0; i < 360;){
        points.append(QVector<double>());
        x = x0 + r*cos((270 + i) * PI / 180.0);
        y = y0 + r*sin((270 + i) *  PI / 180.0);
        points[vertex - 1].append(x);
        points[vertex - 1].append(y);
        i += 360/num_point;
        vertex+=1;
    }
}

window_graph::~window_graph(){
    delete interface;
}
