/*
  Warnings:

  - You are about to drop the column `booking_date` on the `Booking` table. All the data in the column will be lost.
  - You are about to drop the column `cancelled_at` on the `Booking` table. All the data in the column will be lost.
  - You are about to drop the column `check_in_date` on the `Booking` table. All the data in the column will be lost.
  - You are about to drop the column `check_out_date` on the `Booking` table. All the data in the column will be lost.
  - You are about to drop the column `hotel_id` on the `Booking` table. All the data in the column will be lost.
  - You are about to drop the column `room_id` on the `Booking` table. All the data in the column will be lost.
  - You are about to drop the column `total_price` on the `Booking` table. All the data in the column will be lost.
  - You are about to drop the column `user_id` on the `Booking` table. All the data in the column will be lost.
  - You are about to drop the column `created_at` on the `Hotel` table. All the data in the column will be lost.
  - You are about to drop the column `owner_id` on the `Hotel` table. All the data in the column will be lost.
  - You are about to drop the column `total_reviews` on the `Hotel` table. All the data in the column will be lost.
  - You are about to drop the column `booking_id` on the `Review` table. All the data in the column will be lost.
  - You are about to drop the column `created_at` on the `Review` table. All the data in the column will be lost.
  - You are about to drop the column `hotel_id` on the `Review` table. All the data in the column will be lost.
  - You are about to drop the column `user_id` on the `Review` table. All the data in the column will be lost.
  - You are about to drop the column `created_at` on the `Room` table. All the data in the column will be lost.
  - You are about to drop the column `hotel_id` on the `Room` table. All the data in the column will be lost.
  - You are about to drop the column `max_occupany` on the `Room` table. All the data in the column will be lost.
  - You are about to drop the column `price_per_night` on the `Room` table. All the data in the column will be lost.
  - You are about to drop the column `room_number` on the `Room` table. All the data in the column will be lost.
  - You are about to drop the column `room_type` on the `Room` table. All the data in the column will be lost.
  - You are about to drop the column `created_at` on the `User` table. All the data in the column will be lost.
  - A unique constraint covering the columns `[bookingId]` on the table `Review` will be added. If there are existing duplicate values, this will fail.
  - A unique constraint covering the columns `[userId,bookingId]` on the table `Review` will be added. If there are existing duplicate values, this will fail.
  - A unique constraint covering the columns `[hotelId,roomNumber]` on the table `Room` will be added. If there are existing duplicate values, this will fail.
  - Added the required column `checkInDate` to the `Booking` table without a default value. This is not possible if the table is not empty.
  - Added the required column `checkOutDate` to the `Booking` table without a default value. This is not possible if the table is not empty.
  - Added the required column `hotelId` to the `Booking` table without a default value. This is not possible if the table is not empty.
  - Added the required column `roomId` to the `Booking` table without a default value. This is not possible if the table is not empty.
  - Added the required column `totalPrice` to the `Booking` table without a default value. This is not possible if the table is not empty.
  - Added the required column `userId` to the `Booking` table without a default value. This is not possible if the table is not empty.
  - Added the required column `ownerId` to the `Hotel` table without a default value. This is not possible if the table is not empty.
  - Added the required column `totalReviews` to the `Hotel` table without a default value. This is not possible if the table is not empty.
  - Added the required column `bookingId` to the `Review` table without a default value. This is not possible if the table is not empty.
  - Added the required column `hotelId` to the `Review` table without a default value. This is not possible if the table is not empty.
  - Added the required column `userId` to the `Review` table without a default value. This is not possible if the table is not empty.
  - Added the required column `hotelId` to the `Room` table without a default value. This is not possible if the table is not empty.
  - Added the required column `maxOccupancy` to the `Room` table without a default value. This is not possible if the table is not empty.
  - Added the required column `pricePerNight` to the `Room` table without a default value. This is not possible if the table is not empty.
  - Added the required column `roomNumber` to the `Room` table without a default value. This is not possible if the table is not empty.
  - Added the required column `roomType` to the `Room` table without a default value. This is not possible if the table is not empty.

*/
-- DropForeignKey
ALTER TABLE "Booking" DROP CONSTRAINT "Booking_hotel_id_fkey";

-- DropForeignKey
ALTER TABLE "Booking" DROP CONSTRAINT "Booking_room_id_fkey";

-- DropForeignKey
ALTER TABLE "Booking" DROP CONSTRAINT "Booking_user_id_fkey";

-- DropForeignKey
ALTER TABLE "Hotel" DROP CONSTRAINT "Hotel_owner_id_fkey";

-- DropForeignKey
ALTER TABLE "Review" DROP CONSTRAINT "Review_booking_id_fkey";

-- DropForeignKey
ALTER TABLE "Review" DROP CONSTRAINT "Review_hotel_id_fkey";

-- DropForeignKey
ALTER TABLE "Review" DROP CONSTRAINT "Review_user_id_fkey";

-- DropForeignKey
ALTER TABLE "Room" DROP CONSTRAINT "Room_hotel_id_fkey";

-- DropIndex
DROP INDEX "Review_booking_id_key";

-- DropIndex
DROP INDEX "Review_user_id_booking_id_key";

-- DropIndex
DROP INDEX "Room_hotel_id_room_number_key";

-- AlterTable
ALTER TABLE "Booking" DROP COLUMN "booking_date",
DROP COLUMN "cancelled_at",
DROP COLUMN "check_in_date",
DROP COLUMN "check_out_date",
DROP COLUMN "hotel_id",
DROP COLUMN "room_id",
DROP COLUMN "total_price",
DROP COLUMN "user_id",
ADD COLUMN     "bookingDate" TIMESTAMP(3) NOT NULL DEFAULT CURRENT_TIMESTAMP,
ADD COLUMN     "cancelledAt" TIMESTAMP(3),
ADD COLUMN     "checkInDate" TIMESTAMP(3) NOT NULL,
ADD COLUMN     "checkOutDate" TIMESTAMP(3) NOT NULL,
ADD COLUMN     "hotelId" TEXT NOT NULL,
ADD COLUMN     "roomId" TEXT NOT NULL,
ADD COLUMN     "totalPrice" DOUBLE PRECISION NOT NULL,
ADD COLUMN     "userId" TEXT NOT NULL;

-- AlterTable
ALTER TABLE "Hotel" DROP COLUMN "created_at",
DROP COLUMN "owner_id",
DROP COLUMN "total_reviews",
ADD COLUMN     "createdAt" TIMESTAMP(3) NOT NULL DEFAULT CURRENT_TIMESTAMP,
ADD COLUMN     "ownerId" TEXT NOT NULL,
ADD COLUMN     "totalReviews" INTEGER NOT NULL;

-- AlterTable
ALTER TABLE "Review" DROP COLUMN "booking_id",
DROP COLUMN "created_at",
DROP COLUMN "hotel_id",
DROP COLUMN "user_id",
ADD COLUMN     "bookingId" TEXT NOT NULL,
ADD COLUMN     "createdAt" TIMESTAMP(3) NOT NULL DEFAULT CURRENT_TIMESTAMP,
ADD COLUMN     "hotelId" TEXT NOT NULL,
ADD COLUMN     "userId" TEXT NOT NULL;

-- AlterTable
ALTER TABLE "Room" DROP COLUMN "created_at",
DROP COLUMN "hotel_id",
DROP COLUMN "max_occupany",
DROP COLUMN "price_per_night",
DROP COLUMN "room_number",
DROP COLUMN "room_type",
ADD COLUMN     "createdAt" TIMESTAMP(3) NOT NULL DEFAULT CURRENT_TIMESTAMP,
ADD COLUMN     "hotelId" TEXT NOT NULL,
ADD COLUMN     "maxOccupancy" INTEGER NOT NULL,
ADD COLUMN     "pricePerNight" DOUBLE PRECISION NOT NULL,
ADD COLUMN     "roomNumber" TEXT NOT NULL,
ADD COLUMN     "roomType" TEXT NOT NULL;

-- AlterTable
ALTER TABLE "User" DROP COLUMN "created_at",
ADD COLUMN     "createdAt" TIMESTAMP(3) NOT NULL DEFAULT CURRENT_TIMESTAMP;

-- CreateIndex
CREATE UNIQUE INDEX "Review_bookingId_key" ON "Review"("bookingId");

-- CreateIndex
CREATE UNIQUE INDEX "Review_userId_bookingId_key" ON "Review"("userId", "bookingId");

-- CreateIndex
CREATE UNIQUE INDEX "Room_hotelId_roomNumber_key" ON "Room"("hotelId", "roomNumber");

-- AddForeignKey
ALTER TABLE "Hotel" ADD CONSTRAINT "Hotel_ownerId_fkey" FOREIGN KEY ("ownerId") REFERENCES "User"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "Room" ADD CONSTRAINT "Room_hotelId_fkey" FOREIGN KEY ("hotelId") REFERENCES "Hotel"("id") ON DELETE CASCADE ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "Booking" ADD CONSTRAINT "Booking_userId_fkey" FOREIGN KEY ("userId") REFERENCES "User"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "Booking" ADD CONSTRAINT "Booking_roomId_fkey" FOREIGN KEY ("roomId") REFERENCES "Room"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "Booking" ADD CONSTRAINT "Booking_hotelId_fkey" FOREIGN KEY ("hotelId") REFERENCES "Hotel"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "Review" ADD CONSTRAINT "Review_userId_fkey" FOREIGN KEY ("userId") REFERENCES "User"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "Review" ADD CONSTRAINT "Review_hotelId_fkey" FOREIGN KEY ("hotelId") REFERENCES "Hotel"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "Review" ADD CONSTRAINT "Review_bookingId_fkey" FOREIGN KEY ("bookingId") REFERENCES "Booking"("id") ON DELETE RESTRICT ON UPDATE CASCADE;
