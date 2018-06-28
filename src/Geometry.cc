//
// Created by student on 08.05.18.
//

#include <G4VPhysicalVolume.hh>
#include <Geometry.hh>
#include <G4Box.hh>
#include <G4NistManager.hh>
#include "G4SystemOfUnits.hh"
#include <G4LogicalVolume.hh>
#include <G4PVPlacement.hh>
#include <G4VisAttributes.hh>

G4VPhysicalVolume *Geometry::Construct() {
    G4double world_size = 5*m;
    auto world = new G4Box("world", world_size/2.,world_size/2.,world_size/2.);
    auto world_log = new G4LogicalVolume(world,G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR"),"world_log");
    world_log->SetVisAttributes(G4VisAttributes::Invisible);


    auto box = new G4Box("box",40,40,40);
    auto box_log = new G4LogicalVolume(box,G4NistManager::Instance()->FindOrBuildMaterial("G4_BGO"),"box_log");
    new G4PVPlacement(nullptr,G4ThreeVector(),box_log,"box_pvp",world_log,false,0);
    return new G4PVPlacement(nullptr,G4ThreeVector(),world_log,"world_pvp", nullptr,false,0);
}

Geometry::Geometry() {
    box_size = 10*cm;
    mName = "G4_BGO";
}

