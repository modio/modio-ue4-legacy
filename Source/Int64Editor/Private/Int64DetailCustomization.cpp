// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "Int64DetailCustomization.h"
#include "PropertyEditing.h"
#include "Int64.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Input/SEditableTextBox.h"

#define LOCTEXT_NAMESPACE "FInt64DetailCustomization"

TSharedRef<IPropertyTypeCustomization> FInt64DetailCustomization::MakeInstance()
{
	return MakeShareable( new FInt64DetailCustomization() );
}

void FInt64DetailCustomization::CustomizeHeader( TSharedRef<IPropertyHandle> StructPropertyHandle, FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& CustomizationUtils )
{
	PropertyHandle = StructPropertyHandle;

	// create struct header
	HeaderRow
		.NameContent()
		[
			PropertyHandle->CreatePropertyNameWidget()
		]
		.ValueContent()
		.MinDesiredWidth( 325.0f )
		.MaxDesiredWidth( 325.0f )
		[
			SNew( SHorizontalBox )

			+ SHorizontalBox::Slot()
			.FillWidth( 1.0f )
			[
				// text box
				SAssignNew( TextBox, SEditableTextBox )
				.ClearKeyboardFocusOnCommit( false )
				.IsEnabled( !PropertyHandle->IsEditConst() )
				.OnTextCommitted( this, &FInt64DetailCustomization::HandleTextBoxTextCommited )
				.SelectAllTextOnCommit( true )
				.Text( this, &FInt64DetailCustomization::HandleTextBoxText )
			]
		];
}

void FInt64DetailCustomization::CustomizeChildren( TSharedRef<IPropertyHandle> StructPropertyHandle, IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& CustomizationUtils )
{
}

FText FInt64DetailCustomization::HandleTextBoxText() const
{
	TArray<void*> RawData;
	PropertyHandle->AccessRawData( RawData );

	if( RawData.Num() != 1 )
	{
		return LOCTEXT( "MultipleValues", "Multiple Values" );
	}

	if( RawData[0] == nullptr )
	{
		return FText::GetEmpty();
	}

	FInt64* Int64 = (FInt64*)RawData[0];
	return FText::FromString( Int64->ToString() );
}

void FInt64DetailCustomization::HandleTextBoxTextCommited( const FText& NewText, ETextCommit::Type CommitInfo )
{
	if( PropertyHandle.IsValid() )
	{
		TArray<void*> RawData;
		PropertyHandle->AccessRawData( RawData );

		PropertyHandle->NotifyPreChange();

		int64 Value = FCString::Atoi64( *NewText.ToString() );
		for( auto RawDataInstance : RawData )
		{
			*(FInt64*)RawDataInstance = FInt64( Value );
		}

		PropertyHandle->NotifyPostChange();
		PropertyHandle->NotifyFinishedChangingProperties();
	}
}

#undef LOCTEXT_NAMESPACE