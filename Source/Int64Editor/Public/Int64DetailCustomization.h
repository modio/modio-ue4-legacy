// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "IPropertyTypeCustomization.h"


/**
* Customizes the UI for the details panel of FInt64
*/
class FInt64DetailCustomization : public IPropertyTypeCustomization
{
public:
	virtual ~FInt64DetailCustomization() {}

	// Create instance for registration
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();

	/**
	 * Called when the header of the property (the row in the details panel where the property is shown)
	 * If nothing is added to the row, the header is not displayed
	 *
	 * @param PropertyHandle			Handle to the property being customized
	 * @param HeaderRow					A row that widgets can be added to
	 * @param StructCustomizationUtils	Utilities for customization
	 */
	virtual void CustomizeHeader( TSharedRef<IPropertyHandle> StructPropertyHandle, FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& CustomizationUtils ) override;

	/**
	 * Called when the children of the property should be customized or extra rows added
	 *
	 * @param PropertyHandle			Handle to the property being customized
	 * @param StructBuilder				A builder for adding children
	 * @param StructCustomizationUtils	Utilities for customization
	 */
	virtual void CustomizeChildren( TSharedRef<IPropertyHandle> StructPropertyHandle, IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& CustomizationUtils ) override;
protected:
	/** Handles committing the text in the editable text box. */
	void HandleTextBoxTextCommited( const FText& NewText, ETextCommit::Type CommitInfo );

	/** Handles getting the text to be displayed in the editable text box. */
	FText HandleTextBoxText() const;
protected:
	/** Holds a handle to the property being edited. */
	TSharedPtr<IPropertyHandle> PropertyHandle;

	/** Holds the text box for editing the Int64. */
	TSharedPtr<class SEditableTextBox> TextBox;
};
