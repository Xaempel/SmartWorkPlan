#include "include/models/PrintModel.hpp"

void PrintModel::startPrint(QStringList workerNameLists, QList<QPair<QStringList, QString>*> workersShiftsDate)
{
   QPrinter printer;

   printer.setPageSize(QPageSize(QPageSize::A4));

   // if I'm printing vertically instead of horizontally,
   // it's possible that the error is caused by the printer settings and not the code,
   // it will check the settings and set the printing Orientations to landscape
   printer.setPageOrientation(QPageLayout::Landscape);

   QPainter painter;
   painter.begin(&printer);

   paintStaticElements(painter, workerNameLists.size());
   paintWorker(painter, workerNameLists, workersShiftsDate);

   painter.end();
}

void PrintModel::paintStaticElements(QPainter& painter, int workerNumber)
{
   // the parts of the text below are placeholders that
   // are waiting for proper functionality but i need them here to adjust the layout properly in the future
   // the fields will be more customizable trust me
   // Placeholders start with PH and the datatype in () you want them to be in the future e.g. PH Month (M)

   painter.setRenderHint(QPainter::Antialiasing);

   const QPoint posofconstMonthLabel {40, 75};
   const QPoint posofChoicedMonthLabel {200, 75};
   const QRect rectofChoicedMonthFrame {150, 60, 135, 20};

   painter.drawText(posofconstMonthLabel, "MONTH:");
   painter.drawText(posofChoicedMonthLabel, "PH (M)");
   painter.drawRect(rectofChoicedMonthFrame);

   const QPoint posofconstYearLabel {315, 75};

   const QPoint posofChoicedYearLabel {380, 75};
   const QRect rectofChoicedYearFrame {370, 60, 60, 20};

   painter.drawText(posofconstYearLabel, "YEAR:");
   painter.drawText(posofChoicedYearLabel, "PH (Y)");
   painter.drawRect(rectofChoicedYearFrame);

   const QPoint pointsofWorkActivityLabel {750, 85};
   const QRect rectofWorkActivityFrame {700, 60, 300, 40};

   painter.drawText(pointsofWorkActivityLabel, "activities PH (ACTIVITY TYPE)");
   painter.drawRect(rectofWorkActivityFrame);

   const QPoint pointsofconstWorkNormLabel {40, 95};
   const QPoint pointsofChoicedWorkNormLabel {150, 95};

   painter.drawText(pointsofconstWorkNormLabel, "Norm");
   painter.drawText(pointsofChoicedWorkNormLabel, "PH (WH)"); // WH == Working hour in a month

   const QPoint pointsofActivivitiesatGivenCompanyLabel {170, 30};
   const QPoint pointsofActivivitiesatGivenCompanyObjectLabel {730, 30};
   const QLine rectofBeautifierLineforCompanyThings {170, 35, 925, 35};

   painter.drawText(pointsofActivivitiesatGivenCompanyLabel, "SCHEDULE OF ACTIVITIES at PH (a given company)");
   painter.drawText(pointsofActivivitiesatGivenCompanyObjectLabel, "Object: PH (Company Object)");
   painter.drawLine(rectofBeautifierLineforCompanyThings);

   const QPoint pointsofLastNameTitleLabel {40, 135};
   const QPoint pointsofNameTitleLabel {40, 150};
   const QRect rectofNameandLastNameFrame {160, 120, 20, 35};

   painter.drawText(pointsofLastNameTitleLabel, "Last Name");
   painter.drawText(pointsofNameTitleLabel, "and Name");
   painter.drawRect(rectofNameandLastNameFrame);

   const QRect rectofEmptyUpBox {40, 120, 120, 35}; // this box is a beautifier for worker name and last name title box
   painter.drawRect(rectofEmptyUpBox);

   int xPointforDayCounterBox {180};

   int dayCounterloop {1};
   const int monthDays {30}; // this is constant thing however in the future these thing will be a choice for user and be a dynamical

   while (dayCounterloop <= monthDays) {
      QPoint pointforDayCounterBoxLabel {xPointforDayCounterBox + 5, 143};
      QRect rectforDayCounterBoxFrame {xPointforDayCounterBox, 120, 25, 35};

      painter.drawRect(rectforDayCounterBoxFrame);
      painter.drawText(pointforDayCounterBoxLabel, QString::number(dayCounterloop));
      xPointforDayCounterBox += 25;
      dayCounterloop++;
   }

   const QPoint pointsofWorkHourseBoxTitle {935, 144};
   const QRect rectofWorkHourseBoxFrame {930, 120, 35, 35};

   painter.drawText(pointsofWorkHourseBoxTitle, "Hr");
   painter.drawRect(rectofWorkHourseBoxFrame);

   const QPoint pointsofWorkDaysBoxTitle {967, 144};
   const QRect rectofWorkDaysBoxTitle {965, 120, 35, 35};

   painter.drawText(pointsofWorkDaysBoxTitle, "Day");
   painter.drawRect(rectofWorkDaysBoxTitle);

   int yPosofHrandDaylongRect {155};
   int yPosofHrandDayshortRect {190};

   int YpointsHrShortRect {190};

   int YpointsDayShortRect {190};

   int loopInfoBoxinWorkerScheduleCounter {0};
   while (loopInfoBoxinWorkerScheduleCounter < workerNumber) {
      QRect rectofHourslongBoxes {930, yPosofHrandDaylongRect, 35, 35};
      QRect rectofDaylongBoxes {965, yPosofHrandDaylongRect, 35, 35};

      QRect rectofHoursshortBoxes {930, yPosofHrandDayshortRect, 35, 20};
      QRect rectofDayshortBoxes {965, yPosofHrandDayshortRect, 35, 20};

      painter.drawRect(rectofHourslongBoxes);
      painter.drawRect(rectofDaylongBoxes);

      painter.drawRect(rectofHoursshortBoxes);
      painter.drawRect(rectofDayshortBoxes);

      yPosofHrandDayshortRect += 55;
      yPosofHrandDaylongRect += 55;
      loopInfoBoxinWorkerScheduleCounter++;
   }
}

void PrintModel::paintWorker(QPainter& painter, QStringList workerNameLists, QList<QPair<QStringList, QString>*> workersShiftsDate)
{
   int yPointsWorkerNameandLastName {155};
   int yPointsWorkerShortRect {190};
   int yPointsWorkerLongRect {155};

   for (const QString& workerName : workerNameLists) {
      int spaceIndex    = workerName.indexOf(' ');
      QString firstName = workerName.left(spaceIndex);
      QString lastName  = workerName.mid(spaceIndex + 1);

      QPoint pointsofWorkerName {40, yPointsWorkerNameandLastName + 20};
      QPoint pointsofWorkerLastName {40, yPointsWorkerNameandLastName + 40};
      QRect rectofWorkerNameandlastNameFrame {40, yPointsWorkerNameandLastName, 120, 55};

      painter.drawText(pointsofWorkerName, firstName);
      painter.drawText(pointsofWorkerLastName, lastName);
      painter.drawRect(rectofWorkerNameandlastNameFrame);

      const int xPosofWorkerNamelastNameEmptyBox {160};
      painter.drawRect(xPosofWorkerNamelastNameEmptyBox, yPointsWorkerNameandLastName, 20, 20);
      painter.drawRect(xPosofWorkerNamelastNameEmptyBox, yPointsWorkerNameandLastName + 18, 20, 20);
      painter.drawRect(xPosofWorkerNamelastNameEmptyBox, yPointsWorkerNameandLastName + 35, 20, 20);

      yPointsWorkerNameandLastName += 55;

      const int monthdays {30};

      int xPointsLongRect {180};

      for (int i = 0; i < monthdays; i++) {
         QRect rectofLongWorkerShiftBox {xPointsLongRect, yPointsWorkerLongRect, 25, 38};
         painter.drawRect(rectofLongWorkerShiftBox);
         xPointsLongRect += 25;
      }

      int xPointsShortRect {180};

      for (int i = 0; i < monthdays; i++) {
         QRect rectofShortWorkerShiftBox {xPointsShortRect, yPointsWorkerShortRect, 25, 20};
         painter.drawRect(rectofShortWorkerShiftBox);
         xPointsShortRect += 25;
      }

      yPointsWorkerLongRect += 55;
      yPointsWorkerShortRect += 55;
   }

   QRect rectofClearSquare {40, yPointsWorkerNameandLastName, 140, 130}; // This square is to maintain the symmetry of the work plan
   painter.drawRect(rectofClearSquare);

   auto createDownInfoBoxes = [&yPointsWorkerNameandLastName, &painter](QString text, int xPosofBoxesText, int xPosofBoxesFrame, int numbertoSubtractforBoxSmaller) {
      const QPoint pointsofInfoBoxTitle {xPosofBoxesText, yPointsWorkerNameandLastName + 25};
      const QRect rectofInfoBox {xPosofBoxesFrame, yPointsWorkerNameandLastName, 300 - numbertoSubtractforBoxSmaller, 130};

      painter.drawText(pointsofInfoBoxTitle, text);
      painter.drawRect(rectofInfoBox);
   };

   QLine underLineforInfoBoxTitles {180, yPointsWorkerNameandLastName + 30, 1000, yPointsWorkerNameandLastName + 30};
   painter.drawLine(underLineforInfoBoxTitles);
   createDownInfoBoxes("Made", 300, 180, 0);
   createDownInfoBoxes("Checked", 600, 480, 0);
   createDownInfoBoxes("Approved", 860, 780, 80);

   const int xPointMove {25};
   const int yPointMove {55};
   const int xPointValueReset {185};
   int xPoint {185};
   int yPoint {180};

   for (auto i : workersShiftsDate) {
      auto currentShiftsList {i->first};

      for (auto j : currentShiftsList) {
         xPoint = xPointValueReset;

         // set good xPoint basic on j.toInt size
         for (int day = 0; day < j.toInt(); day++) {
            xPoint += xPointMove;
         }

         painter.drawText(xPoint, yPoint, "X");
      }

      yPoint += yPointMove;
   }
}