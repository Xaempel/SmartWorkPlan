#include "../include/models/printmodel.hpp"

// Overall, this file is one of the worst I've ever written.
// Ps those weird rect that are made by paintWorker and overlapping each other,
// it's not a bug, it's a feature

void PrintModel::startPrint(QStringList workerNameLists)
{
   QPrinter printer;
   QPainter painter;

   printer.setPageSize(QPageSize(QPageSize::A4));
   // if I'm printing vertically instead of horizontally, 
   // it's possible that the error is caused by the printer settings and not the code, 
   // it will check the settings and set the printing Orientations to landscape
   printer.setPageOrientation(QPageLayout::Landscape);
   painter.begin(&printer);

   paintStaticElements(painter, workerNameLists.size());
   paintWorker(painter, workerNameLists);

   painter.end();
}

void PrintModel::paintStaticElements(QPainter& painter, int workerNumber)
{
   // the parts of the text below are placeholders that
   // are waiting for proper functionality but i need them here to adjust the layout properly in the future
   // the fields will be more customizable trust me
   // Placeholders start with PH and the datatype in () you want them to be in the future e.g. PH Month (M)

   painter.setRenderHint(QPainter::Antialiasing);

   painter.drawText(40, 60, 100, 100, 1, "MONTH:");
   painter.drawText(200, 60, 135, 20, 1, "PH (M)");
   painter.drawRect(150, 60, 135, 20);

   painter.drawText(315, 60, 135, 20, 1, "YEAR:");
   painter.drawText(380, 60, 60, 20, 1, "PH (Y)");
   painter.drawRect(370, 60, 60, 20);

   painter.drawText(750, 70, 300, 40, 1, "activities PH (ACTIVITY TYPE)");
   painter.drawRect(700, 60, 300, 40);

   painter.drawText(40, 80, 100, 100, 1, "Norm");
   painter.drawText(150, 80, 100, 100, 1, "PH (WH)"); // WH == Working hour in a month

   painter.drawText(170, 15, 500, 500, 1, "SCHEDULE OF ACTIVITIES at PH (a given company)");
   painter.drawText(730, 15, 500, 500, 1, "Object: PH (Company Object)");
   painter.drawLine(170, 35, 925, 35);

   painter.drawText(40, 120, 100, 100, 1, "SurName\nand Name");
   painter.drawRect(40, 120, 120, 35);
   painter.drawRect(160, 120, 20, 35);

   int LoopNumber {1};

   int XLoopPoint {180};

   while (LoopNumber <= 30) {
      painter.drawRect(XLoopPoint, 120, 25, 35);
      painter.drawText(XLoopPoint, 130, 25, 35, 1, QString::number(LoopNumber));
      XLoopPoint += 25;
      LoopNumber++;
   }

   painter.drawText(935, 130, 35, 35, 1, "Hr");
   painter.drawRect(930, 120, 35, 35);

   int YPointHrLongRect {155};
   int YPointHrShortRect {190};

   painter.drawText(967, 130, 35, 35, 1, "Day");
   painter.drawRect(965, 120, 35, 35);

   int YPointDayLongRect {155};
   int YPointDayShortRect {190};

   int LoopVar {0};
   while (LoopVar < workerNumber) {
      painter.drawRect(930, YPointHrLongRect, 35, 35);
      painter.drawRect(930, YPointHrShortRect, 35, 20);
      YPointHrLongRect += 55;
      YPointHrShortRect += 55;

      painter.drawRect(965, YPointDayLongRect, 35, 35);
      painter.drawRect(965, YPointDayShortRect, 35, 20);

      YPointDayLongRect += 55;
      YPointDayShortRect += 55;

      LoopVar++;
   }
}

void PrintModel::paintWorker(QPainter& painter, QStringList workerNameLists)
{
   int YPointWorker {155};

   int YPointWorkerLongRect {155};
   int YPointWorkerShortRect {190};

   for (const QString& workerName : workerNameLists) {
      int spaceIndex    = workerName.indexOf(' ');
      QString firstName = workerName.left(spaceIndex);
      QString lastName  = workerName.mid(spaceIndex + 1);

      painter.drawText(40, YPointWorker, 120, 55, 1, firstName + '\n' + lastName);
      painter.drawRect(40, YPointWorker, 120, 55);

      painter.drawRect(160, YPointWorker, 20, 20);
      painter.drawRect(160, YPointWorker + 18, 20, 20);
      painter.drawRect(160, YPointWorker + 35, 20, 20);

      YPointWorker += 55;

      int XPointLongRect {180};
      for (int i = 0; i < 30; i++) {
         painter.drawRect(XPointLongRect, YPointWorkerLongRect, 25, 38);
         XPointLongRect += 25;
      }

      int XPointShortRect {180};
      for (int i = 0; i < 30; i++) {
         painter.drawRect(XPointShortRect, YPointWorkerShortRect, 25, 20);
         XPointShortRect += 25;
      }

      YPointWorkerLongRect += 55;
      YPointWorkerShortRect += 55;
   }

   painter.drawRect(40, YPointWorker, 140, 130);

   painter.drawText(300, YPointWorker + 12, 100, 100, 1, "Made");
   painter.drawRect(180, YPointWorker, 300, 130);

   painter.drawText(600, YPointWorker + 12, 100, 100, 1, "Checked");
   painter.drawRect(480, YPointWorker, 300, 130);

   painter.drawText(860, YPointWorker + 12, 100, 100, 1, "Approved");
   painter.drawRect(780, YPointWorker, 220, 130);

   painter.drawLine(180, YPointWorker + 30, 1000, YPointWorker + 30);
}